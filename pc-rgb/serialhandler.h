#ifndef SERIALHANDLER_H
#define SERIALHANDLER_H


class SerialHandler
{
public:
    SerialHandler();
    void set_led(int channel, int id, char r, char g, char b);
};

#endif // SERIALHANDLER_H
