#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

 #include <QAudioInput>

class AudioRecorder : public QAudioInput
{
public:
    AudioRecorder();
};

void list_devices();

#endif // AUDIORECORDER_H
