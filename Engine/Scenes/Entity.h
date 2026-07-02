#pragma once
#include <entt/entity/entity.hpp>
#include "ThriveAssert.h"
#include <utility>

namespace Thrive
{
    class Scene;

    /*
    *  @brief 
    * 
    * 
    * 
    */
    class Entity
    {
    public:
        Entity() = default;

        Entity(entt::entity handle, Scene* scene)
            : m_EntityHandle(handle), m_Scene(scene)
        {
        }

        operator bool() const
        {
            return m_EntityHandle != entt::null;
        }

        //
       explicit operator entt::entity() const
        {
            return m_EntityHandle;
        }

        entt::entity GetHandle() const
        {
            return m_EntityHandle;
        }


        //--------------------------------------------------------
        // Components
        //--------------------------------------------------------


        template<typename T, typename... Args>
        T& AddComponent(Args&&... args)
        {
            THRIVE_ASSERT(!HasComponent<T>(), "Entity already has component");

            return m_Scene->GetRegistry().emplace<T>(m_EntityHandle, std::forward<Args>(args)...); 
        }


        template<typename T>
         T& GetComponent()
        {
            THRIVE_ASSERT(HasComponent<T>(), "Entity does not have component!");

            return m_Scene->GetRegistry().get<T>(m_EntityHandle);
        }



        template<typename T> 
        const T& GetComponent() const
        {
            THRIVE_ASSERT(HasComponent<T>(), "Entity does not have component!"); 
            
            return m_Scene->GetRegistry().get<T>(m_EntityHandle); 
        }


        template <typename T> 
        bool HasComponent() const
        {
            return m_Scene->GetRegistry().all_of<T>(m_EntityHandle); 
        }


        template <typename T>
        void RemoveComponent()
        {
            THRIVE_ASSERT(HasComponent<T>(), "Entity does not have component"); 

            m_Scene->GetRegistry().remove<T>(m_EntityHandle); 
        }


    private:
        entt::entity m_EntityHandle{ entt::null };
        Scene* m_Scene = nullptr;
    };
}