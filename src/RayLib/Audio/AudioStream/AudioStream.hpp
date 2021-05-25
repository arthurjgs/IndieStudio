/**
 * @file AudioStream.hpp
 * @brief 
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma	once

#include <raylib.h>

namespace RayLib {
    namespace Audio {
        class AudioStream {
            public:
                AudioStream() = delete;
                AudioStream(const unsigned int &sampleRate, const unsigned int &sampleSize, const unsigned int &channels);
                AudioStream(const AudioStream &cpy) = delete;
                AudioStream &operator = (const AudioStream &cpy) = delete;
                ~AudioStream();

                inline unsigned int &getSampleRate() { return (this->__sampleRate); }
                inline unsigned int &getSampleSize() { return (this->__sampleRate); }
                inline unsigned int &getChannels() { return (this->__sampleRate); }                
            
                inline unsigned int getSampleRate() const { return (this->__sampleRate); }
                inline unsigned int getSampleSize() const { return (this->__sampleRate); }
                inline unsigned int getChannels() const { return (this->__sampleRate); }   
            
                void UpdateAudioStream(const void *data, const int &samplesCount);
                bool IsAudioStreamProcessed();
                void PlayAudioStream();
                void PauseAudioStream();
                void ResumeAudioStream();
                bool IsAudioStreamPlaying();
                void StopAudioStream();
                void SetAudioStreamVolume(const float &volume);
                void SetAudioStreamPitch(const float &pitch);
            protected:
            private:
                unsigned int __sampleRate;
                unsigned int __sampleSize;
                unsigned int __channels;
                ::AudioStream __stream;
        };
    }
}