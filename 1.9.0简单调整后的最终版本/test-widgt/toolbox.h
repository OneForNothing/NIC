#include <QToolBox>
#include <QGroupBox>
#include <QLabel>
#include <QHBoxLayout>
#include<QDebug>

class ToolBox : public QToolBox
{
    Q_OBJECT                                    //只有加入了Q_OBJECT，你才能使用QT中的signal和slot机制

public:
    ToolBox(QWidget *parent = 0)
        : QToolBox(parent)
    {
        initUI();                                     //初始化UI

        // 连接信号槽
        connect(this, &QToolBox::currentChanged, this, &ToolBox::onCurrentChanged);
    }

private:
    void initUI() {
        struct User {
            bool bVIP;  // 会员
            QString strName;  // 名字
            QString strIcon;  // 图像
            QString strDesc;  // 个人说明
        } user[3][5] =
        {
            {
                {true, QStringLiteral("香香公主"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("金庸笔下的第一美女")},
                {true, QStringLiteral("小龙女"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("玉女心经")},
                {true, QStringLiteral("王语嫣"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("熟读各派武学秘笈")},
                {false, QStringLiteral("赵敏"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("大元第一美人")},
                {false, QStringLiteral("周芷若"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("光复汉家河山，光大峨嵋")}
            },

            {
                {true, QStringLiteral("萧峰"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("丐帮帮主 - 智勇双全、胆略过人、豪迈飒爽")},
                {true, QStringLiteral("令狐冲"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("独孤九剑")},
                {true, QStringLiteral("杨过"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("黯然销魂掌")},
                {false, QStringLiteral("郭靖"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("降龙十八掌")},
                {false, QStringLiteral("胡一刀"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("辽东大侠")}
            },

            {
                {true, QStringLiteral("金轮法王"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("龙象般若功")},
                {true, QStringLiteral("丁春秋"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("星宿老仙，法力无边")},
                {false, QStringLiteral("裘千仞"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("铁掌水上飘")},
                {false, QStringLiteral("成昆"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("混元霹雳手")},
                {false, QStringLiteral("李莫愁"), ":/pic/QQ图片20161204200816.bmp", QStringLiteral("冰魄银针，杀人如麻")}
            }
        };

        QStringList groupList;
        groupList << QStringLiteral("大美女") << QStringLiteral("大英雄") << QStringLiteral("大恶人");

        // 初始化列表
        for (int i = 0; i < sizeof(user)/sizeof(user[0]); i++)
        {
            QGroupBox *pGroupBox = new QGroupBox(this);
            QVBoxLayout *pLayout = new QVBoxLayout(pGroupBox);

            // 添加好友
            for (int j = 0; j < sizeof(user[0])/sizeof(user[0][0]); ++j)
            {
                QWidget *pWidget = initWidget(user[i][j].bVIP, user[i][j].strName,
                                              user[i][j].strIcon, user[i][j].strDesc);
                pLayout->addWidget(pWidget);
            }
            pLayout->addStretch();
            pLayout->setSpacing(10);
            pLayout->setContentsMargins(10, 10, 10, 10);

            // 添加分组
            addItem(pGroupBox, groupList.at(i));
        }
    }

    QWidget* initWidget(bool bVIP, const QString &name,
                        const QString &icon, const QString &desc = "") {
        QWidget *pWidget = new QWidget(this);
        QLabel *pPixmapLabel = new QLabel(this);
        QLabel *pNameLabel = new QLabel(this);
        QLabel *pDescLabel = new QLabel(this);

        // 图像 名称 描述
        QPixmap p = QPixmap(icon).scaled(50,50);
        //pPixmapLabel->setPixmap(QPixmap(icon));
         pPixmapLabel->setPixmap(p);
        pNameLabel->setText(name);
        pDescLabel->setText(desc);

        // VIP名字为红色；否则，白色
        pNameLabel->setStyleSheet(QString("color: %1;").arg(bVIP ? "rgb(240, 30, 40)" : "white"));
        pDescLabel->setStyleSheet("color: gray;");

        QVBoxLayout *pVLayout = new QVBoxLayout();
        pVLayout->addStretch();
        pVLayout->addWidget(pNameLabel);
        pVLayout->addWidget(pDescLabel);
        pVLayout->addStretch();
        pVLayout->setSpacing(5);
        pVLayout->setContentsMargins(0, 0, 0, 0);

        QHBoxLayout *pHLayout = new QHBoxLayout();
        pHLayout->addWidget(pPixmapLabel);
        pHLayout->addLayout(pVLayout);
        pHLayout->addStretch();
        pHLayout->setContentsMargins(0, 0, 0, 0);

        pWidget->setLayout(pHLayout);

        return pWidget;
    }

private slots:
    void onCurrentChanged(int index) {
        QString strGroup = itemText(index);
        qDebug() << strGroup;
    }
};
