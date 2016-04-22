//
//  ZADBannerViewDelegate.h
//  ZADKit
//
//  Created by Ray Liu on 4/20/16.
//  Copyright © 2016 ZY. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZADBannerView;
@class ZADRequestError;

/// Delegate methods for receiving ZADBannerView state change messages such as ad request status
/// and ad click lifecycle.
@protocol ZADBannerViewDelegate

@optional

#pragma mark Ad Request Lifecycle Notifications

/// Tells the delegate that an ad request successfully received an ad. The delegate may want to add
/// the banner view to the view hierarchy if it hasn't been added yet.
- (void)adViewDidReceiveAd:(ZADBannerView *)bannerView;

/// Tells the delegate that an ad request failed. The failure is normally due to network
/// connectivity or ad availablility (i.e., no fill).
- (void)adView:(ZADBannerView *)bannerView didFailToReceiveAdWithError:(ZADRequestError *)error;

#pragma mark Click-Time Lifecycle Notifications

/// Tells the delegate that a full screen view will be presented in response to the user clicking on
/// an ad. The delegate may want to pause animations and time sensitive interactions.
- (void)adViewWillPresentScreen:(ZADBannerView *)bannerView;

/// Tells the delegate that the full screen view will be dismissed.
- (void)adViewWillDismissScreen:(ZADBannerView *)bannerView;

/// Tells the delegate that the full screen view has been dismissed. The delegate should restart
/// anything paused while handling adViewWillPresentScreen:.
- (void)adViewDidDismissScreen:(ZADBannerView *)bannerView;

/// Tells the delegate that the user click will open another app, backgrounding the current
/// application. The standard UIApplicationDelegate methods, like applicationDidEnterBackground:,
/// are called immediately before this method is called.
- (void)adViewWillLeaveApplication:(ZADBannerView *)bannerView;

@end
