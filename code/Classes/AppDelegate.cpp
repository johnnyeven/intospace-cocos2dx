#include "AppDelegate.h"
#include "SpaceScene.h"
#include "GlobalConfig.h"

int GlobalConfig::scene_width = 960;
int GlobalConfig::scene_height = 640;
int GlobalConfig::block_width = INT16_MAX;
int GlobalConfig::block_height = INT16_MAX;

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		glview->setFrameSize(960, 640);
#endif
        director->setOpenGLView(glview);

		Size frameSize = glview->getFrameSize();
		GlobalConfig::scene_width = frameSize.width;
		GlobalConfig::scene_height = frameSize.height;
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
	
	//Resolution
	auto screenSize = glview->getFrameSize();
	auto designSize = Size(960, 640);
    auto resourceSize = Size(960, 640);
	
    director->setContentScaleFactor(resourceSize.height/designSize.height);
    glview->setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy::NO_BORDER);

    // create a scene. it's an autorelease object
    auto scene = SpaceScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
