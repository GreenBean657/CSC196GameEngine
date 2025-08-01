#pragma once

#include "renderer/core.h"

namespace bean_engine::bean_renderer {

    struct particle {
        bool active = false;
        float lifetime = 1.0f;
        bean_math::vector2<float> position{0.0f, 0.0f};
        bean_math::vector2<float> velocity{0.0f, 0.0f};

        bean_math::color4 color{255, 255, 255};


    };
    class particleSystem {
        public:
        void init(const int poolSize = 2000) noexcept {
        m_particles.resize(poolSize);

        }

        void shutdown() noexcept {

        }

        void update(float dt) noexcept {
            for (auto& particle : m_particles) {

                if (particle.active) {
                    particle.lifetime -= dt;
                    particle.position += particle.velocity * dt;
                    if (particle.lifetime < 0.0f) {
                        particle.active = false;
                    }
                }
            }
        }
        void draw(renderModule& renderer) noexcept {
            for (auto& particle : m_particles) {
                if (particle.active) {
                    renderer.setDrawColor(particle.color);
                    renderer.drawPoint<float>(particle.position);
                }
            }
        }

        void addParticle(const particle& part) noexcept {
            particle* intpart = getFreeParticle();

            if (intpart != nullptr) {
                *intpart = part;
                intpart->active = true;
            }
        }

    private:
        particle* getFreeParticle() noexcept {

            for (auto& particle : m_particles) {
                if (particle.active == false) {
                    return &particle;
                }
            }
            return nullptr;
        }
    private:
        std::vector<particle> m_particles;
    };
}