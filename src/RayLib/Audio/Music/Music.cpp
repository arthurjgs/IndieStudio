/**
 * @file Music.cpp
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Music.hpp"

RayLib::Audio::Music::Music(const std::string &fileName)
{
    this->__filepath = fileName;
    this->__music = ::LoadMusicStream(this->__filepath.c_str());
    this->__playing = false;
}

RayLib::Audio::Music::Music(const std::string &fileType, unsigned char *data, const int &dataSize)
{
    this->__playing = false;
    this->__filepath = "loadFromMemory";
    this->__music = ::LoadMusicStreamFromMemory(fileType.c_str(), data, dataSize);
}

RayLib::Audio::Music::~Music()
{
    ::UnloadMusicStream(this->__music);
}

void RayLib::Audio::Music::PlayMusicStream()
{
    ::PlayMusicStream(this->__music);
    this->__playing = true;
}

bool RayLib::Audio::Music::IsMusicPlaying() const
{
    return (this->__playing);
}

void RayLib::Audio::Music::UpdateMusicStream(const std::string &newMusic) const
{
    Music dummy(newMusic);
    ::UpdateMusicStream(dummy.__music);
}

void RayLib::Audio::Music::StopMusicStream()
{
    this->__playing = false;
    ::StopMusicStream(this->__music);
}

void RayLib::Audio::Music::PauseMusicStream()
{
    this->__playing = false;
    ::PauseMusicStream(this->__music);
}

void RayLib::Audio::Music::ResumeMusicStream()
{
    this->__playing = true;
    ::ResumeMusicStream(this->__music);
}

void RayLib::Audio::Music::SetMusicVolume(const float &volume) const
{
    ::SetMusicVolume(this->__music, volume);
}

void RayLib::Audio::Music::SetMusicPitch(const float &pitch) const
{
    ::SetMusicPitch(this->__music, pitch);
}

float RayLib::Audio::Music::GetMusicTimeLength() const
{
    return (::GetMusicTimeLength(this->__music));
}

float RayLib::Audio::Music::GetMusicTimePlayed() const
{
    return (::GetMusicTimePlayed(this->__music));
}
