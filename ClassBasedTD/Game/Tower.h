#pragma once

namespace CBTD
{
    enum class TowerBuildState : short
    {
        Idle = 0,
        Building,
        Upgrading,
        Downgrading,
        Destroying
    };

    struct TowerData
    {
        float m_Damage;
        float m_Health;
        int m_BaseCost;
        int m_UpgradeCost;
    };

    class Tower
    {
    private:
        TowerData m_Data;
        int m_upgradeStage;
        TowerBuildState m_Buildstate;
        float m_Buff;

    public:
        Tower();
        virtual ~Tower();

        virtual void Upgrade() = 0;
        virtual void Downgrade() = 0;
        const TowerData& GetData() const;
        void Buff(float amount);
    };
}