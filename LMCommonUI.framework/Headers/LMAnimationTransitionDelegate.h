//
//  LMAnimationTransitionDelegate.h
//  LMCommonUI
//
//  Created by lansc on 2024/8/14.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, LMAnimationTransitionType) {
    LMAnimationTransitionType_present = 0,
    LMAnimationTransitionType_dismiss = 1
};

NS_ASSUME_NONNULL_BEGIN

@interface LMAnimationTransitionDelegate : NSObject<UIViewControllerAnimatedTransitioning>

@property (nonatomic, assign) LMAnimationTransitionType type;

@end

NS_ASSUME_NONNULL_END
