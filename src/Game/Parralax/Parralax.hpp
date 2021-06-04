/**
 * @file Parralax.hpp
 * @brief 
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../GameObject.hpp"
#include <vector>
#include "../../RayLib/Texture/Texture.hpp"

namespace Bomberman {
    /**
     * @brief parralax GameObject (HEAVY ON LOADING ONE PARALLAX PER SCENE IS RECOMMANDED)
     * 
     */

    class ParralaxMember {
        public:
            ParralaxMember() = delete;
            ~ParralaxMember() = default;

            ParralaxMember(const std::pair<const std::string, const double> pairData, const Type::Vector<2> &position);

            ParralaxMember(const ParralaxMember &) = delete;
            ParralaxMember(const ParralaxMember &&cpy);

            ParralaxMember &operator = (const ParralaxMember &) = delete;
            ParralaxMember &operator = (const ParralaxMember &&cpy);

            inline RayLib::Texture &getTextOne() { return (this->__textOne); }
            inline RayLib::Texture &getTextTwo() { return (this->__textTwo); }
            inline Type::Vector<2> &getPositionOne() { return (this->__positionOne); }
            inline Type::Vector<2> &getPositionTwo() { return (this->__positionTwo); }
            inline double &getSpeed() { return (this->__speed); }

            inline RayLib::Texture getTextOne() const { return (this->__textOne); }
            inline RayLib::Texture getTextTwo() const { return (this->__textTwo); }
            inline Type::Vector<2> getPositionOne() const { return (this->__positionOne); }
            inline Type::Vector<2> getPositionTwo() const { return (this->__positionTwo); }
            inline double getSpeed() const { return (this->__speed); }

            void drawTextures() const;
            void update(const double &elapsed);
        protected:
        private:
            RayLib::Texture __textOne;
            RayLib::Texture __textTwo;
            Type::Vector<2> __positionOne;
            Type::Vector<2> __positionTwo;
            double __speed;
    };
    
    class Parralax : public GameObject {
        public:
            Parralax() = delete;
            Parralax(const Parralax &) = delete;
            Parralax &operator = (const Parralax &) = delete;
            
            Parralax(const std::pair<const std::string, const double> *pathArr, const size_t &arrSize, const std::string &name, const Type::Vector<2> &position, bool display = true);

            ~Parralax() = default;
    
            void render() const;
            void update(const double &elapsed);
        protected:
        private:
            std::vector<ParralaxMember> __container;
            size_t __arrSize;
    };
}