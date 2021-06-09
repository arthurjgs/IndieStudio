/**
 * @file Music.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <raylib.h>
#include <iostream>

namespace RayLib {
    namespace Audio {
        class Music {
            public:
                Music() = delete;
                Music(const std::string &fileName);
                Music(const std::string &fileType, unsigned char *data, const int &dataSize);
                Music(const Music &) = delete;
                Music &operator = (const Music &) = delete;
                ~Music();

                void PlayMusicStream();
                bool IsMusicPlaying() const;
                void UpdateMusicStream() const;
                void StopMusicStream();
                void PauseMusicStream();
                void ResumeMusicStream();
                void SetMusicVolume(const float &volume) const;
                void SetMusicPitch(const float &pitch) const;
                float GetMusicTimeLength() const;
                float GetMusicTimePlayed() const;

                inline std::string getFilePath() const { return (this->__filepath); }
            
            protected:
            private:
                ::Music __music;
                std::string __filepath;
                bool __playing;
        };
    }
}