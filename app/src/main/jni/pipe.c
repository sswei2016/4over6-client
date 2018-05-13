//
// Created by Jason YU on 2018/5/11.
//

#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "pipe.h"

#define min(a, b) ((a) < (b) ? (a) : (b))

pipe_t* pipe_create(const char* name, int buf_size){
    pipe_t* pipe = (pipe_t*)malloc(sizeof(pipe_t));

    mknod(name, S_IFIFO | 0666, 0);
    pipe->fd = open(name, O_RDWR|O_CREAT|O_TRUNC);
    pipe->buf = (char*)malloc(buf_size);
    pipe->buf_size = buf_size;

    return pipe;
}

/*
void pipe_write(pipe_t* pipe, void* buf, int sz){
    write(pipe->fd, buf, sz);
}

void pipe_read(pipe_t* pipe, void* buf, int sz){
    read(pipe->fd, buf, sz);
}

void pipe_clean(pipe_t* pipe){

}

*/