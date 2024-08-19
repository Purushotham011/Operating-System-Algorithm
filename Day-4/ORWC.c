// C program for System calls - open,read,write,close
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFF_SIZE 1024
int main()
{
    int source_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFF_SIZE];

    source_fd = open("D:/Learnings/Operating System-C/Day-4/source.txt", O_RDONLY);
    if (source_fd == -1)
    {
        perror("Error in opening source file");
        return 1;
    }
    dest_fd = open("destination.txt", O_WRONLY | O_CREAT, 0644);
    if (dest_fd == -1)
    {
        perror("Error in opening/creating destination file");
        close(source_fd);
        return 1;
    }

    while ((bytes_read = read(source_fd, buffer, BUFF_SIZE)) > 0)
    {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read)
        {
            perror("Error in writing to destination file");
            close(source_fd);
            close(dest_fd);
            return 1;
        }
    }
    if (bytes_read == -1)
    {
        perror("Error in reading source file");
        return 1;
    }

    close(source_fd);
    close(dest_fd);
    printf("File copied successfully\n");
    return 0;
}