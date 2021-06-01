/**
 * @file Music.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include "../GameObject.hpp"
#include "../../RayLib/Audio/Music/Music.hpp"

namespace Bomberman
{
    class Music : public GameObject{
        public:
            Music() = delete;
            Music(const Bomberman::Music &) = delete;
            Music &operator=(const Bomberman::Music &) = delete;
            Music(const std::string &name, const std::string &filepath, float volume = 0.5f, bool display = true);
            ~Music();
            void setVolume(const float &volume);
            void setPitch(const float &pitch);
            void upVolume(const float &volume);
            void downVolume(const float &volume);
            void upPitch(const float &pitch);
            void downPitch(const float &pitch);
            bool isPlayed() const;
            void play();
            void stop();
            void pause();
            void resume();


        protected:
        private:
            RayLib::Audio::Music _music;
            float _volume;
            float _pitch;

    };
}

#endif /* !MUSIC_HPP_ */
