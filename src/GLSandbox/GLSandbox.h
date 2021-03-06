#ifndef SANDBOX_H
#define SANDBOX_H

#include "GLBase.h"
#include "GLGeometry.h"

using namespace GLGeometry;
using namespace GLBase;

class GLSandbox
{
    //==============================
    // User defined variables and logic
    //==============================

    private:

        
    //==============================
    // Basic implementation of the class
    //==============================

    private:
        // Main application
        Application mApplication;

        // Renderer
        DeferredRenderer mRenderer;
        // Reference to the shader of the Lighting pass
        Shader& mLightingShader;
        // Shaders for the geometry pass
        std::vector<Shader> mGPassShaders;

        // Main camera
        Camera mCamera;

        // Main input handler
        InputHandler mInputHandler;

        // Object used to draw auxiliary geometry
        GLAuxElements mAuxElements;

        // Projection and view matrices
        glm::mat4 mProjection;
        glm::mat4 mView;

        // Vector of GLElemObject instances
        std::vector<GLElemObject*> mElementaryObjects;

        // Vector of model instances
        std::vector<Model> mModels;

        // Lights
        std::vector<Light*> mLights;

        // Shaders
        std::vector<Shader> mShaders;

        // Materials
        std::vector<Material> mMaterials;

        // Cubemap for the sky
        GLCubemap* mSkymap;
            
        // Value of the time elapsed since the last frame. This needs to be updated 
        // every frame
        float mDeltaTime;
        float mLastFrame;
        // Variables to measure the amount of time that each frame takes
        int mFrameCounter;
        float mTotalTime;
        
        // Setup the scene
        void setupScene();

        // Pass pointers to objects to the application, for the input processing
        void setupApplication();

        // Method to run on each frame, to update the scene
        void updateScene();

        // // Main render logic
        // void render();
        //
        // Render the geometry that will use deferred rendering
        void renderDeferred();

        // Render the geometry that will use forward rendering
        void renderForward();

    public:
        // Constructor
        GLSandbox(int width, int height, const char* title);

        // Start the application's loop
        void run();
};

#endif
