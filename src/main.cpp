#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;


class TesterPopup : public geode::Popup<> {

protected:

    bool setup() override {

        this->setTitle("GDPS Tester");

        auto text = CCLabelBMFont::create(
            "Prototype Loaded",
            "bigFont.fnt"
        );

        text->setScale(.5f);
        text->setPosition({
            m_mainLayer->getContentSize().width / 2,
            80
        });

        m_mainLayer->addChild(text);

        return true;
    }


public:

    static TesterPopup* create() {

        auto ret = new TesterPopup();

        if (ret && ret->initAnchored(
            260,
            160
        )) {

            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
};



class $modify(TestLevelInfoLayer, LevelInfoLayer) {


    bool init(GJGameLevel* level) {

        if (!LevelInfoLayer::init(level))
            return false;


        auto sprite =
            CCSprite::createWithSpriteFrameName(
                "GJ_likeBtn_001.png"
            );


        auto button =
            CCMenuItemSpriteExtra::create(
                sprite,
                this,
                menu_selector(
                    TestLevelInfoLayer::onTester
                )
            );


        button->setScale(.75f);


        button->setPosition({
            0,
            -80
        });


        m_buttonMenu->addChild(button);


        return true;
    }



    void onTester(CCObject*) {

        TesterPopup::create()->show();

    }

};
