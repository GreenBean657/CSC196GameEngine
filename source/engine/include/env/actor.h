#pragma once

#include "math/vectors/transform.h"
#include "renderer/model.h"
#include "renderer/core.h"
#include <memory>

#include "math/vectors/vector3.h"

namespace bean_engine::bean_actors {
    class actor {
        public:
            std::string m_name;
            std::string m_tag;

            bean_math::vector2<float> m_velocity{0, 0};
        /**
        * @brief Create a new actor.
        * Create a new actor object, with is an exclusive class designed to manage both a transform and model.
        */
        actor() = default;

        /**
         * @brief Create a new actor.
         * Create a new actor object, with is an exclusive class designed to manage both a transform and model.
         * @param transform Transform properties of the actor.
         * @param model Model of the actor.
         */
        explicit actor(const bean_math::transform& transform, const std::shared_ptr<bean_renderer::model> &model) noexcept {
            this->m_transform = transform;
            this->m_model = model;
        }

        /**
         * @brief Update the actor.
         * @param deltaTime TimeService delta time, as a float.
         */
        virtual void update(float deltaTime);

        /**
         * @brief Draw the actor into the scene.
         * @param renderer Renderer object.
         */
        virtual void draw(const bean_renderer::renderModule &renderer) const;

        /**
         * @brief Get the transform of this Actor.
         * @return Transform Object.
         */
        bean_math::transform& getTransform() noexcept {
            return m_transform;
        }

        virtual ~actor() = default;

    protected:
        bean_math::transform m_transform;
        std::shared_ptr<bean_renderer::model> m_model;
    };
}
