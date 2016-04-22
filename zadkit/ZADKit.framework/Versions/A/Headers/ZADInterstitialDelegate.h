//
//  ZADInterstitialDelegate.h
//  ZADKit
//
//  Created by Ray Liu on 4/20/16.
//  Copyright © 2016 ZY. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZADInterstitial;
@class ZADRequestError;

/// Delegate for receiving state change messages from a ZADInterstitial such as interstitial ad
/// requests succeeding/failing.
@protocol ZADInterstitialDelegate

@optional

#pragma mark Ad Request Lifecycle Notifications

/// Called when an interstitial ad request succeeded. Show it at the next transition point in your
/// application such as when transitioning between view controllers.
- (void)interstitialDidReceiveAd:(ZADInterstitial *)ad;

/// Called when an interstitial ad request completed without an interstitial to
/// show. This is common since interstitials are shown sparingly to users.
- (void)interstitial:(ZADInterstitial *)ad didFailToReceiveAdWithError:(ZADRequestError *)error;

#pragma mark Display-Time Lifecycle Notifications

/// Called just before presenting an interstitial. After this method finishes the interstitial will
/// animate onto the screen. Use this opportunity to stop animations and save the state of your
/// application in case the user leaves while the interstitial is on screen (e.g. to visit the App
/// Store from a link on the interstitial).
- (void)interstitialWillPresentScreen:(ZADInterstitial *)ad;

/// Called before the interstitial is to be animated off the screen.
- (void)interstitialWillDismissScreen:(ZADInterstitial *)ad;

/// Called just after dismissing an interstitial and it has animated off the screen.
- (void)interstitialDidDismissScreen:(ZADInterstitial *)ad;

/// Called just before the application will background or terminate because the user clicked on an
/// ad that will launch another application (such as the App Store). The normal
/// UIApplicationDelegate methods, like applicationDidEnterBackground:, will be called immediately
/// before this.
- (void)interstitialWillLeaveApplication:(ZADInterstitial *)ad;

@end
