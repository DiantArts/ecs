#pragma once

#include <Engine/Core/Ecs/Entity/Container.hpp>
#include <Engine/Core/Ecs/Component/Container.hpp>
#include <Engine/Core/Ecs/System/Container.hpp>
#include <Engine/Core/Ecs/Component/Movable.hpp>
#include <Engine/Core/Ecs/Component/Controllable.hpp>
#include <Engine/Core/AWindow.hpp>



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



protected:

    ::engine::core::ecs::component::Container m_components;
    ::engine::core::ecs::entity::Container m_entities{ m_components };
    ::engine::core::ecs::system::Container m_drawSystems;
    ::engine::core::ecs::system::Container m_systems;



private:

    ::engine::core::AWindow& m_window;

    ::engine::core::ecs::Entity& m_camera{ static_cast<::engine::core::ecs::Entity&>(m_entities.emplace<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Controllable
    >()) };

    bool m_isOver { false };

};



} // namespace engine::core
