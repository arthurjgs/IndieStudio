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
}

RayLib::Audio::Music::Music(const std::string &fileType, unsigned char *data, const int &dataSize)
{
    this->__filepath = "loadFromMemory";
    this->__music = ::LoadMusicStreamFromMemory(fileType.c_str(), data, dataSize);
}

RayLib::Audio::Music::~Music()
{
    ::UnloadMusicStream(this->__music);
}

void RayLib::Audio::Music::PlayMusicStream() const
{
    ::PlayMusicStream(this->__music);
}

bool RayLib::Audio::Music::IsMusicPlaying() const
{
    return (::IsMusicPlaying(this->__music));
}

void RayLib::Audio::Music::UpdateMusicStream(const std::string &newMusic) const
{
    Music dummy(newMusic);
    ::UpdateMusicStream(dummy.__music);
}

void RayLib::Audio::Music::StopMusicStream() const
{
    ::StopMusicStream(this->__music);
}

void RayLib::Audio::Music::PauseMusicStream() const
{
    ::PauseMusicStream(this->__music);
}

void RayLib::Audio::Music::ResumeMusicStream() const
{
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
