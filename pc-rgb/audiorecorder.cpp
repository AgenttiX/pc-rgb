#include "audiorecorder.h"

#include <QAudioRecorder>
#include <QAudioDeviceInfo>
#include <QDebug>


AudioRecorder::AudioRecorder()
{

}

void list_devices() {
    QAudioRecorder* recorder = new QAudioRecorder;
    for(const QString &input : recorder->audioInputs()) {
        qDebug() << input;
    };
    delete recorder;
}
