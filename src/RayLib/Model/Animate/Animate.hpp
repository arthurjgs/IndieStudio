/**
 *  @file   RayLibModel.hpp
 *  @brief  RayLib Model encapsulation
 *  @author Arthur Junges
 *  @date   2021-05-24
 **/

#ifndef BOMBERMAN_RAYLIBMODEL_HPP
#define BOMBERMAN_RAYLIBMODEL_HPP

#include <string>
#include <vector>
#include "raylib.h"
#include <filesystem>
#include <iostream>
#include <algorithm>
#include "../../../Types/Vector/Vector.hpp"

namespace RayLib {
    namespace Models {
        /*! RayLib Model encapsulation */
        class Animate {
        public:
            /*! Create model from @param path path @param position position @param rotationAxis rotation Axis @param rotationAngle rotation Angle and finally @param scale the scale*/
            explicit Animate(const std::string &path, const Type::Vector<3> &position = Type::Vector<3>(0.0f, 0.0f, 0.0f), const Type::Vector<3> &rotationAxis = Type::Vector<3>(0.0f, 0.0f, 0.0f), double rotationAngle = 0.0f, const Type::Vector<3> &scale = Type::Vector<3>(1.0f, 1.0f, 1.0f));
            /*! Function used to display (with animation) the model*/
            void display();
            /*! Function used to set textures for a model. @param path path to png file only @param materialIndex index of the material in the model material list*/
            void setTexture(const std::string &path, int materialIndex);
            /*! Function used to set the animation file (ONLY USED IF THE MODEL IS A .IQM TYPE)*/
            void setAnimation(const std::string &path);
            ~Animate();

            /*! Position setter @param position position to be used*/
            void setPosition(const Type::Vector<3> &position);
            /*! Position getter @return model's position*/
            Type::Vector<3> getPosition();
            /*! Scale setter @param position scale to be used*/
            void setScale(const Type::Vector<3> &scale);
            /*! Scale getter @return model's scale*/
            Type::Vector<3> getScale();
            /*! Rotation Axis setter @param position rotation axis to be used*/
            void setRotationAxis(const Type::Vector<3> &rotationAxis);
            /*! Rotation axis getter @return model's rotation axis*/
            Type::Vector<3> getRotationAxis();
            /*! Rotation Angle setter @param position rotation angle to be used*/
            void setRotationAngle(float rotationAngle);
            /*! Rotation angler getter @return model's rotation angle*/
            double getRotationAngle();
            /*! Reset Animation Frames*/
            void resetAnim();
            std::vector<Model> Models;
        private:
            /*! AnimType enum to know which type of animation it is */
            enum AnimType {
                /*! If the model if an obj list */
                OBJ_LIST,
                /*! If the model if an iqm file */
                IQM
            };
            /*! Model's animation type */
            AnimType _animType;
            /*! Model's path */
            std::string _path;
            /*! Model's files (this is only used if it's an OBJ_LIST animation type */
            std::vector<std::string> _fileList;
            /*! Model's textures list */
            std::vector<Texture2D> _textures;
            /*! Model's animation frame counter */
            int _animFrameCounter;
            /*! Model's animation frame counter (if it's an IQM file)*/
            int _iqmAnimCount;
            /*! Model's animations (if it's an IQM file)*/
            ModelAnimation *_animations;
            /*! Model's position */
            Vector3 _position;
            /*! Model's rotation axis */
            Vector3 _rotationAxis;
            /*! Model's rotation angle */
            float _rotationAngle;
            /*! Model's scale */
            Vector3 _scale;
        };
    }
}

#endif //BOMBERMAN_RAYLIBMODEL_HPP
