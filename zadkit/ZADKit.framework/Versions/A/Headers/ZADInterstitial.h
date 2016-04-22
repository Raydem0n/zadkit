//
//  ZADInterstitial.h
//  ZADKit
//
//  Created by Ray Liu on 4/20/16.
//  Copyright © 2016 ZY. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZADRequest.h"
#import "ZADInterstitialDelegate.h"

@interface ZADInterstitial : UIView

#pragma mark Pre-Request

/// Required value passed in with initWithAdUnitID:.
@property(nonatomic, readonly, copy) NSString *adUnitID;

/// Optional delegate object that receives state change notifications from this ZADInterstitalAd.
@property(nonatomic, weak) id<ZADInterstitialDelegate> delegate;

#pragma mark Making an Ad Request

/// Makes an interstitial ad request. Additional targeting options can be supplied with a request
/// object. Only one interstitial request is allowed at a time.
///
/// This is best to do several seconds before the interstitial is needed to preload its content.
/// Then when transitioning between view controllers show the interstital with
/// presentFromViewController.
- (void)loadRequest:(ZADRequest *)request;

#pragma mark Post-Request

/// Returns YES if the interstitial is ready to be displayed. The delegate's
/// interstitialAdDidReceiveAd: will be called after this property switches from NO to YES.
@property(nonatomic, readonly, assign) BOOL isReady;

/// Returns YES if this object has already been presented. Interstitial objects can only be used
/// once even with different requests.
@property(nonatomic, readonly, assign) BOOL hasBeenUsed;

/// Presents the interstitial ad which takes over the entire screen until the user dismisses it.
/// This has no effect unless isReady returns YES and/or the delegate's interstitialDidReceiveAd:
/// has been received.
///
/// Set rootViewController to the current view controller at the time this method is called. If your
/// application does not use view controllers pass in nil and your views will be removed from the
/// window to show the interstitial and restored when done. After the interstitial has been removed,
/// the delegate's interstitialDidDismissScreen: will be called.
- (void)presentFromRootViewController:(UIViewController *)rootViewController;

@end
