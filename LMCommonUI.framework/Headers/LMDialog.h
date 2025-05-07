//
//  LMDialog.h
//  AqaraHome
//
//  Created by lansc on 2022/2/21.
//  Copyright © 2022 Lumi United Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

///展示方式
typedef NS_ENUM(NSInteger, LMDialogStyle) {
    LMDialogStyleAlert = 0,
    LMDialogStyleSheet
};

///对话框展示模式
typedef NS_ENUM(NSInteger ,LMDialogDisplayType) {
    LMDialogDisplayTypeNormal = 0,//默认,通过present方式
    LMDialogDisplayTypeAddView, //添加到某个view(UIView的子类)上
    LMDialogDisplayTypePresent, //通过present方式
};

///按钮风格
typedef NS_ENUM(NSInteger, LMDialogActionStyle) {
    LMDialogActionStyleDefault = 0,//默认,蓝色
    LMDialogActionStyleCancel, //灰色
    LMDialogActionStyleDelete, //删除,红色
    LMDialogActionStyleBlue_gray, //蓝字灰底
};

///复选框对齐方式
typedef NS_ENUM(NSInteger, LMCheckBoxAlignment) {
    LMCheckBoxAlignmentCenter    = 0,    // Visually centered
    LMCheckBoxAlignmentLeft      = 1,    // Visually left aligned
    LMCheckBoxAlignmentRight     = 2,    // Visually right aligned
};

///显示方式
typedef NS_ENUM(NSInteger, LMDialogContainerStyle) {
    LMDialogContainerStyleFullScreen = 0, /// 全屏
    LMDialogContainerStyleSplitPrimary, /// 左边分屏
    LMDialogContainerStyleSplitSecondary, /// 右边分屏
};

///按钮的布局方式
typedef NS_ENUM(NSInteger, LMDialogButtonStyle) {
    LMDialogButtonStyleAuto = 0, /// 按钮为超过两个时，按钮垂直布局；等于两个是水平布局
    LMDialogButtonStyleVertical, /// 总是垂直布局
};

#pragma mark - 对话框 按钮
@interface LMDialogAction : NSObject

+(instancetype)actionWithTitle:(nullable NSString *)title
                          style:(LMDialogActionStyle)style
                        handler:(void (^ __nullable)(LMDialogAction *action))handler;

@property (nonatomic, copy, readonly, nullable) NSString *title;
@property (nonatomic, assign, readonly) LMDialogActionStyle style;
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

@end


#pragma mark - 对话框 复选框
@interface LMDialogCheckBox : NSObject

+(instancetype)checkBoxWithTitle:(nullable NSString *)title
                        handler:(void (^ __nullable)(LMDialogCheckBox * checkBox))handler;

+(instancetype)checkBoxWithTitle:(nullable NSString *)title
                          alignment:(LMCheckBoxAlignment)alignment
                        handler:(void (^ __nullable)(LMDialogCheckBox * checkBox))handler;

@property (nonatomic, copy, readonly, nullable) NSString *title;
@property (nonatomic, assign, readonly) LMCheckBoxAlignment alignment;
@property (nonatomic, assign, getter=isSelected) BOOL selected;

@end


#pragma mark - 对话框 链接

@interface LMDialogLinkData : NSObject

+ (instancetype)linkData:(NSURL *)url range:(NSRange)range;

@property(nonatomic, strong ,readonly) NSURL *url;
@property(nonatomic, assign ,readonly) NSRange range;

@end


@interface LMDialogLinkAction : NSObject

/// url整个都可点击
+ (instancetype)linkActionWithURL:(NSURL *)url
                          handler:(void (^)(LMDialogLinkAction * action ,LMDialogLinkData * linkData))handler;

/// 描述的一个url可点
+ (instancetype)linkActionWithDesc:(NSString *)desc
                               URL:(NSURL *)url
                            range:(NSRange)range
                          handler:(void (^)(LMDialogLinkAction * action ,LMDialogLinkData * linkData))handler;

/// 描述的多个部分url可点
+ (instancetype)linkActionWithDesc:(NSString *)desc
                         linkDatas:(NSArray <LMDialogLinkData *>*)linkDatas
                          handler:(void (^)(LMDialogLinkAction * action ,LMDialogLinkData * linkData))handler;

@property(nonatomic, strong ,readonly) NSString * desc;

/// 添加可点击
- (void)addLinkData:(LMDialogLinkData *)linkData;
@property(nonatomic, copy, readonly) NSArray <LMDialogLinkData *>*linkDatas;

@end


#pragma mark - 对话框 文本输入框
@interface LMDialogTextField : NSObject

#warning 还需补充输入状态的回调

+(instancetype)textField;

+(instancetype)textFieldWithTextField:(UITextField *)textField;

@property (nonatomic, copy, readonly) UITextField *textField;

@end


#pragma mark - 对话框 菜单按钮
@interface LMDialogMenuData : NSObject

+(instancetype)menuName:(nullable NSString *)name
                imageName:(NSString *)imageName;

@property (nonatomic, copy, nullable) NSString *name;
@property (nonatomic, copy, nullable) NSString *imageName;

@end

@interface LMDialogMenuAction : NSObject

/**
 @[ @[@"name1",@"imageName1"],
    @[@"name2",@"imageName2"],
    @[@"会被抛弃"],
    @[@"name3",@"imageName3",@"这个会被抛弃,取前两个"]
 ]
 数组内数组元素少于2个会被抛弃,大于2个取前两个
 */
+(instancetype)menuArray:(NSArray <NSArray <NSString *>*>*)menuArray
                 handler:(void(^)(NSInteger index))handler;


+(instancetype)menuModels:(NSArray <LMDialogMenuData *>*)menuModels
                  handler:(void(^)(NSInteger index))handler;

@property (nonatomic, copy, readonly, nullable) NSArray <LMDialogMenuData *>* menuModels;

@end


#pragma mark - 对话框 日期选择器
@interface LMDialogDatePicker : NSObject

///会传入当前日期
+(instancetype)datePickerSelectHandler:(void(^)(NSInteger year,NSInteger month,NSInteger day))handler;

+(instancetype)datePicker:(NSDate *)date selectHandler:(void(^)(NSInteger year,NSInteger month,NSInteger day))handler;

@property (nonatomic ,assign ,readonly) NSInteger year;
@property (nonatomic ,assign ,readonly) NSInteger month;
@property (nonatomic ,assign ,readonly) NSInteger day;

@end


#pragma mark - 对话框 自定义视图协议

@protocol LMDialogCustomProtocol <NSObject>

@optional

///这个会在addsubview:前调用,可以在设置frame之类的
-(void)customViewBeforeAddView:(UIView *)customView;

///这个会在addsubview:后调用,可在这设置约束
-(void)customViewAfterAddView:(UIView *)customView;

@end

#pragma mark - 对话框
@interface LMDialog : NSObject

///创建一个对话框,只有标题和描述信息
+(instancetype)dialogWithTitle:(nullable NSString *)title
                        message:(nullable NSString *)message;

+(instancetype)dialogWithTitle:(nullable NSString *)title
                        message:(nullable NSString *)message
                         style:(LMDialogStyle)style;

+(instancetype)dialogWithTitle:(nullable NSString *)title
                        message:(nullable NSString *)message
                         level:(NSInteger)level;

+(instancetype)dialogWithTitle:(nullable NSString *)title
                        message:(nullable NSString *)message
                         style:(LMDialogStyle)style
                         level:(NSInteger)level;

///会以present的方式从当前控制器弹出
-(void)show;

///弹窗优先级,在同一父视图上,值最大的将会显示,如果相等,后添加的会显示,默认为0
@property (nonatomic, assign) NSInteger level;

///设置弹窗宽度
@property (nonatomic, assign) CGFloat width;

/// 默认UIEdgeInsetsMake(24, 24, 24, 24)
@property (nonatomic, assign) UIEdgeInsets padding;

///添加按钮点击事件
-(void)addAction:(LMDialogAction *)action;
@property (nonatomic, copy, readonly) NSArray<LMDialogAction *> * actions;

///添加图片
-(void)addImage:(UIImage *)image;
-(void)addImage:(UIImage *)image
          onTop:(BOOL)onTop
      autoHight:(BOOL)autoHight;
@property (nonatomic, strong, readonly) UIImage * image;

///添加checkBox
-(void)addCheckBox:(LMDialogCheckBox *)checkBox;
@property (nonatomic, copy, readonly) NSArray<LMDialogCheckBox *> * checkBoxs;

///添加超链接点击事件
-(void)addLinkAction:(LMDialogLinkAction *)linkAction;
@property (nonatomic, copy, readonly) NSArray<LMDialogLinkAction *> * linkActions;

///添加textField
-(void)addTextField:(LMDialogTextField *)textField;
@property (nonatomic, copy, readonly) NSArray<LMDialogTextField *> * textFields;

///添加菜单栏按钮
-(void)addMenuAction:(LMDialogMenuAction *)menuAction;
@property (nonatomic, copy, readonly) NSArray <LMDialogMenuAction *>* menuActions;

///添加日期选择器
-(void)addDatePicker:(LMDialogDatePicker *)datePicker;
@property (nonatomic, copy, readonly) NSArray <LMDialogDatePicker *>* datePickers;

///添加自定义视图
-(void)addCustomView:(UIView <LMDialogCustomProtocol>*)customView;
@property (nonatomic, copy, readonly) NSArray <UIView <LMDialogCustomProtocol>*>* customViews;

///自定义背景颜色(默认白色)
@property (nonatomic, strong, nullable) UIColor * customBackgroundColor;
@property (nonatomic, copy, nullable) NSString * title;
@property (nonatomic, copy, nullable) NSString * message;
@property (nonatomic, strong, nullable) UIFont * messageFont; //UI要加新样式,用这个
@property (nonatomic, strong, nullable) UIColor * messageColor;//UI要加新样式,用这个
@property (nonatomic, readonly) LMDialogDisplayType displayType;
@property (nonatomic, readonly) LMDialogStyle style;
@property (nonatomic, readonly) LMDialogContainerStyle containerStyle;
@property (nonatomic, assign) LMDialogButtonStyle buttonStyle;//默认自动布局

///点击按钮自动关闭 默认true
@property (nonatomic, assign) BOOL clickAutoDismiss;

///触摸背景是否隐藏弹窗,当没有按钮事件时,会设置为YES
@property (nonatomic, assign) BOOL backgoundTapDismissEnable;
///弹窗标志,用于区分弹窗
@property (nonatomic, copy) NSString * flag;

//获取当前展示在UIView/UIController上的弹窗
+(LMDialog *)currentDialogForTarget:(id)target;

//获取展示在UIView/UIController上的弹窗
+(NSArray <LMDialog *> *)dialogsForTarget:(id)target;

@end


@interface LMDialog (display)

///手动隐藏弹出
-(void)dismiss;
-(void)dismiss:(void(^)(void))completion;

///展示在特定的view上
-(void)displayToView:(UIView *)view;

///显示在window上,可分全屏/左边/右边
-(void)showInWindow:(UIWindow *)window
              style:(LMDialogContainerStyle)style;

///从特定的控制器进行present
-(void)presentToViewController:(UIViewController *)viewController;

///通过present的方式弹出,可分全屏/左边/右边
-(void)presentToViewController:(UIViewController *)viewController
                          style:(LMDialogContainerStyle)style;

@end

NS_ASSUME_NONNULL_END
