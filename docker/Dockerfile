FROM gcc:latest

RUN apt-get -y update && \
    apt-get -y install gdb libedit-dev nasm clang && \
    git clone https://github.com/yrp604/rappel.git && \
    cd rappel/ && \
    CC=clang make && \
    ln -s /rappel/bin/rappel /usr/local/bin/rappel

RUN apt-get -y apt-get -y install tcl-dev tk-dev flex bison && \
    curl -o /opt/sim.tar http://csapp.cs.cmu.edu/3e/sim.tar && \
    tar -xvf /opt/sim.tar

# -fcommonオプションを付与 => misc/Makefile、pipe/Makefile
# CFLAGS=-Wall -O1 -g -fcommona
# LCFLAGS=-O1 -fcommon
# https://stackoverflow.com/questions/63152352/fail-to-compile-the-y86-simulatur-csapp
