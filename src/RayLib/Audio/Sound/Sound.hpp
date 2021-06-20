/**
 * @file Sound.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include <iostream>
#include <raylib.h>

namespace RayLib {
    namespace Audio {
        class Sound {
            public:
                Sound() = delete;
                Sound(const std::string &filePath);
                Sound(const Sound &) = delete;
                Sound &operator = (const Sound &) = delete;
                ~Sound();

                inline std::string getFilepath() const { return (this->__filePath); }
            
                void UpdateSound(const void *data, const int &samplesCount) const;
                void PlayRaySound() const;
                void StopSound() const;
                void PauseSound() const;
                void ResumeSound() const;
                void PlaySoundMulti() const;
                void StopSoundMulti(void) const;
                int GetSoundsPlaying(void) const;
                bool IsSoundPlaying() const;
                void SetSoundVolume(const float &volume) const;
                void SetSoundPitch(const float &pitch) const;
            protected:
            private:
                std::string __filePath;
                ::Sound __sound;
        };
    }
}