/**
 * @file Music.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Music.hpp"

Bomberman::Music::Music(const std::string &name, const std::string &filepath, float volume, bool display) :
GameObject(name, Bomberman::GameObject::MUSIC, Type::Vector<3>(0.0f, 0.0f, 0.0f), display),
_music(filepath),
_volume(volume)
{
    _pitch = 1.0f;
    this->play();
}

Bomberman::Music::~Music() = default;

void Bomberman::Music::setVolume(const float &volume)
{
    if (volume > 0 && volume < 1.0f)
    {
        _volume = volume;
        _music.SetMusicVolume(_volume);
    }
}

void Bomberman::Music::setPitch(const float &pitch)
{
    if (pitch >= 0 && pitch <= 2.0f)
    {
        _pitch = pitch;
        _music.SetMusicPitch(_pitch);
    }
}

void Bomberman::Music::upVolume(const float &volume)
{
    if (volume >= 0 && volume <= 1.0f)
    {
        if (_volume + volume <= 1.0f)
        {
            _volume += volume;
            _music.SetMusicVolume(_volume);
        }
    }
}

void Bomberman::Music::downVolume(const float &volume)
{
    if (volume >= 0 && volume <= 1.0f)
    {
        if (_volume - volume >= 0.0f)
        {
            _volume -= volume;
            _music.SetMusicVolume(_volume);
        }
    }
}

void Bomberman::Music::upPitch(const float &pitch)
{
    if (pitch >= 0 && pitch <= 2.0f)
    {
        if (_pitch + pitch <= 2.0f)
        {
            _pitch += pitch;
            _music.SetMusicPitch(_pitch);
        }
    }
}

void Bomberman::Music::downPitch(const float &pitch)
{
    if (pitch >= 0 && pitch <= 2.0f)
    {
        if (_pitch - pitch >= 0.0f)
        {
            _pitch -= pitch;
            _music.SetMusicPitch(_pitch);
        }
    }
}

bool Bomberman::Music::isPlayed() const
{
    return _music.IsMusicPlaying();
}

void Bomberman::Music::play()
{
    if (!_music.IsMusicPlaying())
        _music.PlayMusicStream();
}

void Bomberman::Music::stop()
{
    _music.StopMusicStream();
}

void Bomberman::Music::pause()
{
    if (_music.IsMusicPlaying())
        _music.PauseMusicStream();
}

void Bomberman::Music::resume()
{
    if (!_music.IsMusicPlaying())
        _music.ResumeMusicStream();
}

void Bomberman::Music::render() const {}

void Bomberman::Music::update(const double &elapsed)
{
    (void) elapsed;
    _music.UpdateMusicStream();
}
