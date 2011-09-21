//
//  MainMenuLayer.cpp
//  BolognieTouch-iOS
//
//  Created by  on 11-9-21.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include "MainMenuLayer.h"
#include "GameScene.h"
using namespace cocos2d;

bool MainMenuLayer::init() {
    if (! CCLayer::init() ) {
        return false;
    }
    
    displayMenu();
    
    return true;
}

void MainMenuLayer::displayMenu() {
    CCMenuItemSprite *startButton = CCMenuItemSprite::itemFromNormalSprite(CCSprite::spriteWithSpriteFrameName("op_start1.png"), CCSprite::spriteWithSpriteFrameName("op_start2.png"), this, menu_selector(MainMenuLayer::startButtonCallback));
    
    CCMenuItemSprite *continueButton = CCMenuItemSprite::itemFromNormalSprite(CCSprite::spriteWithSpriteFrameName("op_continue1.png"), CCSprite::spriteWithSpriteFrameName("op_continue2.png"), this, menu_selector(MainMenuLayer::startButtonCallback));

    CCMenuItemSprite *optionButton = CCMenuItemSprite::itemFromNormalSprite(CCSprite::spriteWithSpriteFrameName("op_option1.png"), CCSprite::spriteWithSpriteFrameName("op_option2.png"), this, menu_selector(MainMenuLayer::startButtonCallback));
    
    CCMenuItemSprite *extraButton = CCMenuItemSprite::itemFromNormalSprite(CCSprite::spriteWithSpriteFrameName("op_extra1.png"), CCSprite::spriteWithSpriteFrameName("op_extra2.png"), this, menu_selector(MainMenuLayer::startButtonCallback));
    
    CCMenuItemSprite *exitButton = CCMenuItemSprite::itemFromNormalSprite(CCSprite::spriteWithSpriteFrameName("op_exit1.png"), CCSprite::spriteWithSpriteFrameName("op_exit2.png"), this, menu_selector(MainMenuLayer::exitButtonCallback));
     
    mainMenu = CCMenu::menuWithItems(startButton, continueButton, optionButton, extraButton, exitButton, NULL);
     
    //TODO: edge alias
    
    mainMenu->setPosition(ccp(757.0f, 306.0f));
    mainMenu->alignItemsVerticallyWithPadding(34.0f);
    
    addChild(mainMenu, 0);
}

void MainMenuLayer::startButtonCallback(CCObject* pSender) {
    CCDirector::sharedDirector()->replaceScene(GameScene::node());
}

void MainMenuLayer::exitButtonCallback(CCObject* pSender) {
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}