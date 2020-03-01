FROM ubuntu:latest

RUN apt-get update && apt-get install -y build-essential qtmultimedia5-dev libqt5serialport5-dev qt5-default qt5-qmake

COPY . /build
WORKDIR /build
RUN qmake pc-rgb.pro -Wall \
    && make \
    && ls
