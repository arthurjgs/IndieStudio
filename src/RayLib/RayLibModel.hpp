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

namespace RayLib {
    /*! RayLib Model encapsulation */
    class IndieModel {
    public:
        /*! Create model from @param path path @param position position @param rotationAxis rotation Axis @param rotationAngle rotation Angle and finally @param scale the scale*/
        explicit IndieModel(const std::string &path, Vector3 position = {0.0f, 0.0f, 0.0f}, Vector3 rotationAxis = {0.0f, 0.0f, 0.0f}, double rotationAngle = 0.0f, Vector3 scale = {1.0f, 1.0f, 1.0f});
        /*! Function used to display (with animation) the model*/
        void display();
        /*! Function used to set textures for a model. @param path path to png file only @param materialIndex index of the material in the model material list*/
        void setTexture(const std::string &path, int materialIndex);
        /*! Function used to set the animation file (ONLY USED IF THE MODEL IS A .IQM TYPE)*/
        void setAnimation(const std::string &path);
        ~IndieModel();

        /*! Position setter @param position position to be used*/
        void setPosition(Vector3 position);
        /*! Position getter @return model's position*/
        Vector3 getPosition();
        /*! Scale setter @param position scale to be used*/
        void setScale(Vector3 scale);
        /*! Scale getter @return model's scale*/
        Vector3 getScale();
        /*! Rotation Axis setter @param position rotation axis to be used*/
        void setRotationAxis(Vector3 rotationAxis);
        /*! Rotation axis getter @return model's rotation axis*/
        Vector3 getRotationAxis();
        /*! Rotation Angle setter @param position rotation angle to be used*/
        void setRotationAngle(double rotationAngle);
        /*! Rotation angler getter @return model's rotation angle*/
        double getRotationAngle();

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
        double _rotationAngle;
        /*! Model's scale */
        Vector3 _scale;
    };
}

#endif //BOMBERMAN_RAYLIBMODEL_HPP
