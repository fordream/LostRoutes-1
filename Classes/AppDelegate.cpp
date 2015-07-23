#include "AppDelegate.h"
#include "HelloWorldScene.h"

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
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
	

	auto screenSize = glview->getFrameSize();
	auto designSize = Size(320,480);
	auto resourceSize = Size(640,960);
	std::vector<std::string> searchPaths;

	if (screenSize.height >960)
	{
		designSize = Size(320,568);
		searchPaths.push_back("hd");

	}
	else
	{
		searchPaths.push_back("hd");
	}
	director->setContentScaleFactor(resourceSize.width/designSize.width);
	FileUtils::getInstance()->setSearchPaths(searchPaths);
	glview->setDesignResolutionSize(designSize.width,designSize.height,ResolutionPolicy::FIXED_WIDTH);
    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();
	director->runWithScene(scene);
    // run
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