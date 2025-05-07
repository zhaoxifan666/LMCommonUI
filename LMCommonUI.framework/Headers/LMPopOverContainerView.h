//
//  LMPopOverContainerView.h
//  LMCommonUI
//
//  Created by lansc on 2023/9/6.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger,LMArrowDirection){

    //箭头位置
    
    LMArrowDirectionLeftTop=1,//左上
    LMArrowDirectionLeftMid,//左中
    LMArrowDirectionLeftBottom,//左下
    LMArrowDirectionRightTop,//右上
    LMArrowDirectionRightMid,//右中
    LMArrowDirectionRightBottom,//右下
    LMArrowDirectionUpLeft,//上左
    LMArrowDirectionUpMid,//上中
    LMArrowDirectionUpRight,//上右
    LMArrowDirectionDownLeft,//下左
    LMArrowDirectionDownMid,//下中
    LMArrowDirectionDownRight,//下右

};
@interface LMPopOverContainerView : UIView
@property (nonatomic, strong) UIView *backView;
// 默认为0
@property (nonatomic, assign) CGFloat animateDuration;
@property (nonatomic, assign) BOOL isTapDismiss; // 默认YES
@property (nonatomic, strong) UIColor *containerColor;

-(instancetype)initWithOrigin:(CGPoint)origin
                        Width:(CGFloat)width
                       Height:(CGFloat)height
                    Direction:(LMArrowDirection)direction;//初始化

-(void)popToView:(UIView *)targetView;//弹出视图
-(void)popToKeyWindow;
-(void)dismiss;//隐藏视图
@end

NS_ASSUME_NONNULL_END
