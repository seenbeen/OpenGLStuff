#ifndef CSEA_RENDER_OVERLAY_HPP
#define CSEA_RENDER_OVERLAY_HPP
#include <set>

#include <CSE/CSEA/render/overlayrenderable.hpp>

namespace CSEA { namespace Render {
    class Window;
    class Viewport;

    class Overlay {
    friend class Window;
    friend class Viewport;

        std::set<OverlayRenderable*> renderables;

        bool isActive;
        // active meaning does this overlay update. Saves you some frame ops if you need it - still renders just fine

        Overlay();

        void update(double deltaTime);
        void render(unsigned int viewportWidth, unsigned int viewportHeight);
    public:
        ~Overlay();
        bool addOverlayRenderable(OverlayRenderable *overRend);
        bool removeOverlayRenderable(OverlayRenderable *overRend);
        void setIsActive(bool isActive);
        bool getIsActive();
    };
}}
#endif