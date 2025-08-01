#include "actor.h"
namespace bean_engine::bean_actors {
    class firereset : public actor {
    public:
        float speed = 0.0f;

        firereset() = default;
        firereset(const bean_engine::bean_math::transform& transform, const std::shared_ptr<bean_engine::bean_renderer::model> &model) noexcept : actor(transform, model) {
            m_name = "droppedreseter";
            m_tag = "droppedreseter";
        };
        void onCollision(actor* other) override;
        void update(float dt) noexcept override;
    };
}