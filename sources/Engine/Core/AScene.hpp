#pragma once

#include <Engine/Core/Ecs/Entity/Container.hpp>
#include <Engine/Core/Ecs/Component/Container.hpp>
#include <Engine/Core/Ecs/System/Container.hpp>
#include <Engine/Core/Ecs/Component/Position.hpp>
#include <Engine/Core/Ecs/Component/Controllable.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Drawable.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Camera.hpp>
#include <Engine/Core/AWindow.hpp>

namespace engine::core::event { class KeyPressed; }
namespace engine::core::event { class KeyReleased; }
namespace engine::core::event { class MouseMoved; }



namespace engine::core {



class AScene {

public:

    // ------------------------------------------------------------------ *structors

    AScene(
        ::engine::core::AWindow& window
    );

    virtual ~AScene() = 0;



    // ------------------------------------------------------------------ Loop

    auto isOver() const
        -> bool;

    void ends();



    // ------------------------------------------------------------------ Update

    void update();

    virtual void onUpdate();



    // ------------------------------------------------------------------ Draw

    void draw() const;

    virtual void onDraw() const;



    // ------------------------------------------------------------------ MainControllable

    auto getMainEntityControllable() const
        -> const ::engine::core::ecs::component::Controllable&;

    auto getMainEntityControllable()
        -> ::engine::core::ecs::component::Controllable&;



protected:

    ::engine::core::ecs::component::Container m_components;
    ::engine::core::ecs::entity::Container m_entities{ m_components };
    ::engine::core::ecs::system::Container m_drawSystems;
    ::engine::core::ecs::system::Container m_systems;



private:

    ::engine::core::AWindow& m_window;

    bool m_isOver { false };

    ::engine::core::Clock m_systemsClock;
    mutable ::engine::core::Clock m_drawSystemsClock;



    ::engine::core::ID m_cameraID{ m_entities.emplace(
        ::engine::core::ecs::component::Position{ 0.0f, 0.0f,  3.0f },
        ::engine::core::ecs::component::Controllable{},
        ::engine::graphic::opengl::ecs::component::Camera{ m_window }
    ).getID() };

    ::engine::core::ID m_controlledID{ m_cameraID };

};



} // namespace engine::core
