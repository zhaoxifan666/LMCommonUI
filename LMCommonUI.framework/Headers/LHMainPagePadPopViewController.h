//
//  LHMainPagePadPopViewController.h
//  LHMainPagePadPopViewController
//
//  Created by Silver on 2021/9/18.
//  Copyright © 2021 Lumi United Technology Co., Ltd. All rights reserved.
//

#import <LMFramework/LMFramework.h>

NS_ASSUME_NONNULL_BEGIN

@interface LHMainPagePadPopViewController : LHPopViewController

//@property (nonatomic, copy) void(^switchHomeHandler)(void);
@property (nonatomic, copy) void(^selectItemHandler)(NSInteger index);

@property (nonatomic, copy) NSArray<NSString *> * titles;
@property (nonatomic, copy) NSArray<NSString *> * icons;

@end

NS_ASSUME_NONNULL_END
