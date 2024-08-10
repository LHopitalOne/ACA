#include <chrono>
#include <thread>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <sys/ioctl.h>
#include <errno.h>

void set_raw_mode(int fd) {
    struct termios term;
    if (tcgetattr(fd, &term) == -1) {
        perror("tcgetattr");
        exit(EXIT_FAILURE);
    }
    term.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    if (tcsetattr(fd, TCSANOW, &term) == -1) {
        perror("tcsetattr");
        exit(EXIT_FAILURE);
    }
}

void reset_terminal_mode(int fd, struct termios *original_term) {
    if (tcsetattr(fd, TCSANOW, original_term) == -1) {
        perror("tcsetattr");
        exit(EXIT_FAILURE);
    }
}

void simulate_input(const char *input) {
    int master_fd;
    char slave_name[100];
    struct termios original_term;

    if (tcgetattr(STDIN_FILENO, &original_term) == -1) {
        perror("tcgetattr");
        exit(EXIT_FAILURE);
    }

    // Open a pseudo-terminal master
    master_fd = posix_openpt(O_RDWR | O_NOCTTY);
    if (master_fd == -1) {
        perror("posix_openpt");
        exit(EXIT_FAILURE);
    }

    // Grant access to the slave pseudo-terminal
    if (grantpt(master_fd) == -1) {
        perror("grantpt");
        close(master_fd);
        exit(EXIT_FAILURE);
    }

    // Unlock the slave pseudo-terminal
    if (unlockpt(master_fd) == -1) {
        perror("unlockpt");
        close(master_fd);
        exit(EXIT_FAILURE);
    }

    // Get the name of the slave pseudo-terminal
    if (ptsname_r(master_fd, slave_name, sizeof(slave_name)) != 0) {
        perror("ptsname_r");
        close(master_fd);
        exit(EXIT_FAILURE);
    }

    // Open the slave pseudo-terminal
    int slave_fd = open(slave_name, O_RDWR | O_NOCTTY);
    if (slave_fd == -1) {
        perror("open slave pty");
        close(master_fd);
        exit(EXIT_FAILURE);
    }

    // Set the slave pty to raw mode
    set_raw_mode(slave_fd);

    // Write the input string to the slave pty
    if (write(slave_fd, input, strlen(input)) == -1) {
        perror("write");
        close(master_fd);
        close(slave_fd);
        exit(EXIT_FAILURE);
    }

    // Reset the terminal mode
    reset_terminal_mode(STDIN_FILENO, &original_term);

    // Close the pseudo-terminal descriptors
    close(master_fd);
    close(slave_fd);
}

int main() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    const char *input = "Hello, simulated input!\n";
    simulate_input(input);
    return 0;
}

