/**
 * @file AudioStream.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "AudioStream.hpp"

RayLib::Audio::AudioStream::AudioStream(const unsigned int &sampleRate, const unsigned int &sampleSize, const unsigned int &channels)
{
    this->__sampleRate = sampleRate;
    this->__sampleSize = sampleSize;
    this->__channels = channels;
    this->__stream = ::InitAudioStream(this->__sampleRate, this->__sampleSize, this->__channels);
}

void RayLib::Audio::AudioStream::UpdateAudioStream(const void *data, const int &samplesCount)
{
    ::UpdateAudioStream(this->__stream, data, samplesCount);
}

bool RayLib::Audio::AudioStream::IsAudioStreamProcessed()
{
    return (::IsAudioStreamProcessed(this->__stream));
}

void RayLib::Audio::AudioStream::PlayAudioStream()
{
    ::PlayAudioStream(this->__stream);
}

void RayLib::Audio::AudioStream::PauseAudioStream()
{
    ::PauseAudioStream(this->__stream);
}

void RayLib::Audio::AudioStream::ResumeAudioStream()
{
    ::ResumeAudioStream(this->__stream);
}

bool RayLib::Audio::AudioStream::IsAudioStreamPlaying()
{
    return (::IsAudioStreamPlaying(this->__stream));
}

void RayLib::Audio::AudioStream::StopAudioStream()
{
    ::StopAudioStream(this->__stream);
}

void RayLib::Audio::AudioStream::SetAudioStreamVolume(const float &volume)
{
    ::SetAudioStreamVolume(this->__stream, volume);
}

void RayLib::Audio::AudioStream::SetAudioStreamPitch(const float &pitch)
{
    ::SetAudioStreamPitch(this->__stream, pitch);
}

RayLib::Audio::AudioStream::~AudioStream()
{
    ::CloseAudioStream(this->__stream);
}
