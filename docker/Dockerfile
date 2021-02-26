FROM gcc:latest

RUN apt-get -y update && \
    apt-get -y install gdb libedit-dev nasm clang && \
    git clone https://github.com/yrp604/rappel.git && \
    cd rappel/ && \
    CC=clang make && \
    ln -s /rappel/bin/rappel /usr/local/bin/rappel
