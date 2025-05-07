//
//  LMDBPopAlertView.h
//  LMDashboard
//
//  Created by Silver on 2021/11/12.
//

#import <UIKit/UIKit.h>
#import <LMFramework/LMFramework.h>

typedef NS_ENUM(NSUInteger, LH_POP_ALERT_TYPE) {
    LH_POP_ALERT_TYPE_STANDARD,   //标准状态，一取消一确定
    LH_POP_ALERT_TYPE_CONFIRM,    //单确定
    LH_POP_ALERT_TYPE_ALERT,      //警告，一取消一红色确定
    LH_POP_ALERT_TYPE_TEXT,       //输入文本
};

NS_ASSUME_NONNULL_BEGIN

/// 确认弹窗
@interface LHPopAlertView : UIView

@property (nonatomic, assign) LH_POP_ALERT_TYPE type;

@property (nonatomic, strong) NSString * title;
@property (nonatomic, strong) NSString * content;
@property (nonatomic, strong) NSString * defaultText;
@property (nonatomic, strong) NSString * confirmTitle;
@property (nonatomic, strong) NSString * cancelTitle;
@property (nonatomic, copy) void(^handler)(NSInteger index);
@property (nonatomic, copy) void(^textAlertHandler)(NSInteger index, NSString * message);

@property (nonatomic, strong) NSString * placeholder;
@property (nonatomic, assign) LHAlertTextVerifyType textVerifyType;
///点击确定后是否自动dismiss,默认YES,为NO时需要主动调用-dismiss方法
@property (nonatomic, assign) BOOL autoDismiss;
@property (nonatomic, assign) BOOL canTapDismiss;

+ (instancetype)showSimpleAlertWithTitle:(NSString *)title content:(NSString *)content confirmTitle:(NSString *)confirmTitle completeHandler:(void(^)(NSInteger index))handler;
+ (instancetype)showConfirmAlertWithTitle:(NSString *)title content:(NSString *)content cancelTitle:(NSString *)cancelTitle confirmTitle:(NSString *)confirmTitle completeHandler:(void(^)(NSInteger index))handler;
+ (instancetype)showTextFieldAlertWithTitle:(NSString *)title placholder:(NSString *)placeholder defaultText:(NSString *)defaultText cancelTitle:(NSString *)cancelTitle confirmTitle:(NSString *)confirmTitle textVerifyType:(LHAlertTextVerifyType)textVerifyType completeHandler:(void(^)(NSInteger index, NSString * message))handler;

+ (instancetype)showConfirmAlertWithTitle:(NSString *)title
                                  content:(NSString *)content
                              cancelTitle:(NSString *)cancelTitle
                             confirmTitle:(NSString *)confirmTitle
                                alertType:(LH_POP_ALERT_TYPE)type
                          completeHandler:(void(^)(NSInteger index))handler;
- (void)dismiss;

@end

NS_ASSUME_NONNULL_END
