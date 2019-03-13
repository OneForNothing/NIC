#include "personlist.h"
#include <QAction>
#include <QIcon>
#include "personlistbuddy.h"
#include<QDebug>
#include"statusbarwidget.h"
#include"addbuddy.h"
#include"log.h"
personList::personList(QListWidget *parent) :
    QListWidget(parent)
{
    logSysInit("qdebug.txt");
    setFocusPolicy(Qt::NoFocus);       // 去除item选中时的虚线边框
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//水平滚动条关闭
    initMenu();
    //this->setGeometry(0,0,200,500);
}
//初始化菜单
void personList::initMenu()
{
    //初始化：
    blankMenu = new QMenu();
    groupMenu = new QMenu();
    personMenu = new QMenu();
    groupNameEdit=new QLineEdit();
    QAction *addGroup = new QAction("添加分组", this);
    QAction *delGroup = new QAction("删除该组", this);
    QAction *rename = new QAction("重命名", this);
    QAction *addBuddy = new QAction("添加好友",this);
    QAction *chatWithBuddy = new QAction("与该好友聊天", this);
    QAction *delBuddy = new QAction("删除好友", this);
    QAction *addgroupchat = new QAction("添加群聊", this);
    //QAction *setname = new QAction("设置备注",this);
    //设置：
    groupNameEdit->setParent(this);  //设置父类
    groupNameEdit->hide(); //设置初始时隐藏
    groupNameEdit->setPlaceholderText("未命名");//设置初始时的内容
    //布局：
    blankMenu->addAction(addGroup);
    groupMenu->addAction(delGroup);
    groupMenu->addAction(rename);
    groupMenu->addAction(addBuddy);
    groupMenu->addAction(addgroupchat);
    personMenu->addAction(chatWithBuddy);
    personMenu->addAction(delBuddy);
    //personMenu->addAction(setname);
    //信息槽：
    connect(groupNameEdit,SIGNAL(editingFinished()),this,SLOT(slotRenameEditFshed()));
    connect(addGroup,SIGNAL(triggered()),this,SLOT(slotAddGroup()));
    connect(delGroup,SIGNAL(triggered()),this,SLOT(slotDelGroup()));
    connect(rename,SIGNAL(triggered()),this,SLOT(slotRename()));
    connect(addBuddy,SIGNAL(triggered()),this,SLOT(slotAddBuddy()));
    connect(chatWithBuddy,SIGNAL(triggered()),this, SLOT(slotChatWithBuddy()));
    connect(delBuddy,SIGNAL(triggered()),this,SLOT(slotDelBuddy()));
    //connect(setname,SIGNAL(triggered()),this,SLOT(slotSetName()));
    connect(addgroupchat,SIGNAL(triggered()),this,SLOT(addchatgroup()));
    //connect(_statusbarwidget,SIGNAL(addnewuser(QString,int)),this,SLOT(addonlinefriend(QString,int)));//9.13中午记：没有连过来，为什么？
}
//初始化组
void personList::initGroup()
{
    //初始化分组：当前在线的用户
    {
    QListWidgetItem *newItem=new QListWidgetItem(QIcon(":/arrowRight"),"   未命名");    //创建一个Item
    newItem->setSizeHint(QSize(this->width(),25));//设置宽度、高度
    this->addItem(newItem);         //加到QListWidget中
    groupMap.insert(newItem,newItem);//加到容器groupMap里，key和value都为组
    isHideMap.insert(newItem,true);  //设置该组隐藏状态
    groupNameEdit->raise();
    groupNameEdit->setText(tr("当前在线的用户")); //设置默认内容
    groupNameEdit->selectAll();        //设置全选
    groupNameEdit->setGeometry(this->visualItemRect(newItem).left(),this->visualItemRect(newItem).top()+1,this->visualItemRect(newItem).width(),this->visualItemRect(newItem).height()-2);//出现的位置
    groupNameEdit->show();              //显示
    groupNameEdit->setFocus();          //获取焦点
   currentItem = newItem;     // 因为要给group命名，所以当前的currentItem设为该group
   onlinegroupitem = newItem; //后面为了唯一确定这一个组
   }
    //添加好友
    {
    personListBuddy *buddy=new personListBuddy();   //创建一个自己定义的信息类
    buddy->headPath=":/image-3/204378.jpg";                          //设置头像路径
    buddy->name->setText("公共聊天室");  //设置用户名
    buddy->sign->setText("uid:99");   //设置个性签名
    QList<QListWidgetItem*> tem = groupMap.keys(currentItem);//当前组对应的项（包括组本身和好友）复制给tem
    //关键代码
    QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem

    QSize size(30,50);
    newItem->setSizeHint(size);

    this->insertItem(row(currentItem)+tem.count(),newItem); //将该newItem插入到后面
    this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
    groupMap.insert(newItem,currentItem);   //加进容器，key为好友，value为组
    newItem->setText("\n\n\n*公共聊天室:99-");      //的确是悄悄添加到用户后面了，预设公共聊天室的uid为99
    if(isHideMap.value(currentItem))          //如果该组是隐藏，则加进去的好友设置为隐藏
         newItem->setHidden(true);
    else                                      //否则，该好友设置为显示
         newItem->setHidden(false);
    }
}

void personList::setuid(int uid)
{
    _uid = uid;
}


//鼠标点击事件
void personList::mousePressEvent(QMouseEvent *event)
{
    QListWidget::mousePressEvent(event); // 如果不调用基类mousePressEvent，item被select会半天不响应,调用父类，让QSS起效，因为QSS基于父类QListWidget，子类就是子窗口，就是最上层窗口，是覆盖在父窗口上的，所以先于父窗口捕获消息
   //防止一种特殊情况：给新item命名、点击其他item或空白处时，指向新item的currentItem被赋予其他item
    if(groupNameEdit->isVisible() && !(groupNameEdit->rect().contains(event->pos())))
    {
        if(groupNameEdit->text()!=NULL)
            currentItem->setText(groupNameEdit->text());
        groupNameEdit->setText("");
        groupNameEdit->hide();
    }
    currentItem = this->itemAt(mapFromGlobal(QCursor::pos()));//鼠标位置的Item，不管右键左键都获取
    if(event->button()==Qt::LeftButton && currentItem!=NULL && currentItem==groupMap.value(currentItem))//如果点击的左键并且是点击的是组
    {
        if(isHideMap.value(currentItem))                                  //如果先前是隐藏，则显示
        {
            foreach(QListWidgetItem* subItem, groupMap.keys(currentItem))//遍历组的对应的项（包括自身和好友）
                if(subItem!=currentItem)                                 //如果是组的话不进行处理
                {
                    subItem->setHidden(false);                            //好友全部显示
                }
            isHideMap.insert(currentItem,false);                          //设置该组为显示状态
            currentItem->setIcon(QIcon(":/arrowDown"));
        }
        else                                                             //否则，先前是显示，则隐藏
        {
            foreach(QListWidgetItem* subItem, groupMap.keys(currentItem))//遍历组的对应的项（包括自身和好友）
                if(subItem!=currentItem)                                 //如果是组的话不进行处理
                {
                    subItem->setHidden(true);                            //好友全部隐藏
                }
             isHideMap.insert(currentItem,true);                          //设置该组为隐藏状态
             currentItem->setIcon(QIcon(":/arrowRight"));
        }
    }
}

void personList::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton&&currentItem!=groupMap.value(currentItem))
    {
        slotChatWithBuddy();
    }
}

//菜单事件，为了显示菜单，点击鼠标右键响应，鼠标点击事件mousePressEvent优先于contextMenuEvent
void personList::contextMenuEvent(QContextMenuEvent *event)
{
    QListWidget::contextMenuEvent(event);           //调用基类事件
    if(currentItem==NULL)                           //如果点击到的是空白处
    {
        blankMenu->exec(QCursor::pos());
        return;
    }
    if(currentItem==groupMap.value(currentItem))    // 如果点击到的是组
        groupMenu->exec(QCursor::pos());
    else                                            //否则点击到的是好友
        personMenu->exec(QCursor::pos());
}
//添加组
void personList::slotAddGroup()
{
    QListWidgetItem *newItem=new QListWidgetItem(QIcon(":/arrowRight"),"   未命名");    //创建一个Item
    newItem->setSizeHint(QSize(this->width(),25));//设置宽度、高度
    this->addItem(newItem);         //加到QListWidget中
    groupMap.insert(newItem,newItem);//加到容器groupMap里，key和value都为组
    isHideMap.insert(newItem,true);  //设置该组隐藏状态
    groupNameEdit->raise();
    groupNameEdit->setText(tr("未命名")); //设置默认内容
    groupNameEdit->selectAll();        //设置全选
    groupNameEdit->setGeometry(this->visualItemRect(newItem).left(),this->visualItemRect(newItem).top()+1,this->visualItemRect(newItem).width(),this->visualItemRect(newItem).height()-2);//出现的位置
    groupNameEdit->show();              //显示
    groupNameEdit->setFocus();          //获取焦点
   currentItem = newItem;     // 因为要给group命名，所以当前的currentItem设为该group
}
//删除组
void personList::slotDelGroup()
{
    foreach(QListWidgetItem* item, groupMap.keys(currentItem))  //遍历该组的所有好友和自身的组
   {
        groupMap.remove(item);   //移除
       delete item;   //删除
    }
    isHideMap.remove(currentItem); //移除
}
//重命名
void personList::slotRename()
{
   groupNameEdit->raise();
   groupNameEdit->setGeometry(this->visualItemRect(currentItem).left(),this->visualItemRect(currentItem).top()+1,this->visualItemRect(currentItem).width(),this->visualItemRect(currentItem).height()-2);//出现的位置
   groupNameEdit->setText(currentItem->text());   //获取该组名内容
    groupNameEdit->show();                        //显示
    groupNameEdit->selectAll();                   //全选
    groupNameEdit->setFocus();                        //获取焦点
}
//添加好友，主要是为了测试功能，实际工程里可以改成动态读取数据库进行添加好友
void personList::slotAddBuddy()
{
    Addbuddy *search = new Addbuddy();
    search->setfromuid(_uid);
    search->show();
}


//删除好友
void personList::slotDelBuddy()
{
   groupMap.remove(currentItem);  //移除该好友
   delete currentItem;            //删除
}
//聊天
void personList::slotChatWithBuddy()
{
    QWidget *buddy = new QWidget();

    buddy = this->itemWidget(currentItem);
    QString tmpMsg = currentItem->text();
    int front = tmpMsg.indexOf("*");
    int mid = tmpMsg.indexOf(":");
    int back = tmpMsg.indexOf("-");
    qDebug()<<"当前选中的用户名："<<tmpMsg.mid(front+1, mid - front - 1)<<"uid:"<<tmpMsg.mid(mid+1, back - mid - 1);
    QString name = tmpMsg.mid(front+1, mid - front - 1);
    int userid = tmpMsg.mid(mid+1, back - mid - 1).toInt();
    emit requestwidget(name,userid);
    qDebug()<<"发射请求新窗口的信号，用户名和uid分别为"<<name<<"--"<<userid;
}


//重命名完成
void personList::slotRenameEditFshed()
{
    if(groupNameEdit->text()!=NULL)      //如果重命名编辑框不为空
        currentItem->setText(groupNameEdit->text());  //更新组名
    groupNameEdit->setText("");
    groupNameEdit->hide();  //隐藏重命名编辑框
}

//在"当前在线的用户"分组中添加用户
void personList::addonlinefriend(QString username, int uid)
{
    qDebug()<<"接收到新用户上线通知，即将在“当前在线的用户”分组中添加用户";
    personListBuddy *buddy=new personListBuddy();   //创建一个自己定义的信息类
    buddy->headPath=":/image-3/204378.jpg";                          //设置头像路径
    buddy->name->setText(username);  //设置用户名
    QString sign = QString("uid:") + QString::number(uid);
    buddy->sign->setText(sign);   //设置个性签名
    QList<QListWidgetItem*> tem = groupMap.keys(onlinegroupitem);//当前组对应的项（包括组本身和好友）复制给tem
    //关键代码
    QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem

    QSize size(30,50);
    newItem->setSizeHint(size);

    this->insertItem(row(onlinegroupitem)+tem.count(),newItem); //将该newItem插入到后面
    this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
    groupMap.insert(newItem,onlinegroupitem);   //加进容器，key为好友，value为组

    QString str1("\n\n\n*");
    QString str2(":");
    QString str3 = QString::number(uid);
    QString str4("-");
    QString str5=str1+username+str2+str3+str4;
    newItem->setText(str5);      //的确是悄悄添加到用户后面了，预设公共聊天室的uid为99
    if(isHideMap.value(onlinegroupitem))          //如果该组是隐藏，则加进去的好友设置为隐藏
         newItem->setHidden(true);
    else                                      //否则，该好友设置为显示
        newItem->setHidden(false);
}

void personList::addbuddy(QString name, int uid)
{
    personListBuddy *buddy=new personListBuddy();   //创建一个自己定义的信息类
    buddy->headPath=":/image-3/204378.jpg";                          //设置头像路径
    buddy->name->setText(name);  //设置用户名
    buddy->sign->setText(QString::number(uid));   //设置个性签名
    QList<QListWidgetItem*> tem = groupMap.keys(currentItem);//当前组对应的项（包括组本身和好友）复制给tem
    //关键代码
    QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem

    QSize size(30,50);
    newItem->setSizeHint(size);

    this->insertItem(row(currentItem)+tem.count(),newItem); //将该newItem插入到后面
    this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
   groupMap.insert(newItem,currentItem);   //加进容器，key为好友，value为组
   QString str1("\n\n\n*");
   QString str2(":");
   QString str3 = QString::number(uid);
   QString str4("-");
   QString str5=str1+name+str2+str3+str4;
   newItem->setText(str5);      //的确是悄悄添加到用户后面了，预设公共聊天室的uid为99
   if(isHideMap.value(currentItem))          //如果该组是隐藏，则加进去的好友设置为隐藏
        newItem->setHidden(true);
   else                                      //否则，该好友设置为显示
       newItem->setHidden(false);
}

void personList::slotSetName()
{
}

void personList::addchatgroup()
{
    addonlinefriend(QString("群聊"),100);
    emit requestnewgroup();
}

