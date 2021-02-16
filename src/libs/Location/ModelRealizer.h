#ifndef _ModelWraper_H_
#define _ModelWraper_H_

#include "dx9render.h"
#include "geometry.h"
#include "vmodule_api.h"

class Lights;

class LocModelRealizer : public Entity
{
    entid_t eid_model;
    Lights *lights;
    VDX9RENDER *rs;
    VGEOMETRY *gs;
    bool bShow;

    //--------------------------------------------------------------------------------------------
    //Конструирование, деструктурирование
    //--------------------------------------------------------------------------------------------
  public:
    LocModelRealizer();
    ~LocModelRealizer();

    //Инициализация
    bool Init() override;
    //Исполнение
    void Execute(uint32_t delta_time);
    void Realize(uint32_t delta_time) const;

    void ProcessStage(Stage stage, uint32_t delta) override
    {
        switch (stage)
        {
        case Stage::execute:
            Execute(delta);
            break;
        case Stage::realize:
            Realize(delta);
            break;
            /*case Stage::lost_render:
              LostRender(delta); break;
            case Stage::restore_render:
              RestoreRender(delta); break;*/
        }
    }

    //Сообщения
    uint64_t ProcessMessage(MESSAGE &message) override;
};

#endif