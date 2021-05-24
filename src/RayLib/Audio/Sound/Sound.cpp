/**
 * @file Sound.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Sound.hpp"

RayLib::Audio::Sound::Sound(const std::string &filePath)
{
    this->__filePath = filePath;
    this->__sound = ::LoadSound(this->__filePath.c_str());
}

RayLib::Audio::Sound::~Sound()
{
    ::UnloadSound(this->__sound);
}

void RayLib::Audio::Sound::UpdateSound(const void *data, const int &samplesCount) const
{
    ::UpdateSound(this->__sound, data, samplesCount);
}

void RayLib::Audio::Sound::PlaySound() const
{
    ::PlaySound(this->__sound);
}

void RayLib::Audio::Sound::StopSound() const
{
    ::StopSound(this->__sound);
}

void RayLib::Audio::Sound::PauseSound() const
{
    ::PauseSound(this->__sound);
}

void RayLib::Audio::Sound::ResumeSound() const
{
    ::ResumeSound(this->__sound);
}

void RayLib::Audio::Sound::PlaySoundMulti() const
{
    ::PlaySoundMulti(this->__sound);
}

void RayLib::Audio::Sound::StopSoundMulti(void) const
{
    ::StopSoundMulti();
}

int RayLib::Audio::Sound::GetSoundsPlaying(void) const
{
    return (::GetSoundsPlaying());
}

bool RayLib::Audio::Sound::IsSoundPlaying() const
{
    return (::IsSoundPlaying(this->__sound));
}

void RayLib::Audio::Sound::SetSoundVolume(const float &volume) const
{
    ::SetSoundVolume(this->__sound, volume);
}

void RayLib::Audio::Sound::SetSoundPitch(const float &pitch) const
{
    ::SetSoundPitch(this->__sound, pitch);
}
