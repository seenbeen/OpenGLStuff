#ifndef CSEA_RENDER_VIEWPORT_HPP
#define CSEA_RENDER_VIEWPORT_HPP

#include <CSE/CSELL/render/renderer.hpp>

#include <CSE/CSEA/render/scene.hpp>
#include <CSE/CSEA/render/camera.hpp>

namespace CSEA { namespace Render {
    class Viewport {
    friend class Renderer;
        unsigned int x, y, width, height;
        bool visible;

        Camera *boundCamera;
        Scene *boundScene;

        void render(CSELL::Render::Renderer *renderer);
    public:
        Viewport(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
        ~Viewport();

        // bind functions can be null to unbind
        void bindCamera(Camera *cam);
        void bindScene(Scene *scene);

        void setPosition(unsigned int x, unsigned int y);
        void setDimensions(unsigned int w, unsigned int h);
        void setVisible(bool visible);
    };
}}
#endif
