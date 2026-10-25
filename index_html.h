// Generated from index.html (DEMO = false). Re-generate after UI changes.
#pragma once
#include <Arduino.h>
const char INDEX_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1, viewport-fit=cover">
<meta name="color-scheme" content="light dark">
<meta name="theme-color" content="#E8EDE9" media="(prefers-color-scheme: light)">
<meta name="theme-color" content="#0E1511" media="(prefers-color-scheme: dark)">
<title>Plant monitor</title>
<style>
:root{
  --bg:#E8EDE9; --surface:#F7F9F7; --ink:#14231A; --ink2:#4C5D52; --line:#D3DBD5;
  --leaf:#2F6B45; --leaf-bg:#DCEBE1; --water:#1F6FAE; --water-bg:#DCE9F4;
  --soil:#6E4B33; --soil2:#7E5840; --warn:#A8410F; --warn-bg:#F6E3D8; --on-water:#FFFFFF;
  --r-lg:22px; --r-md:14px; --r-sm:10px;
  --num:ui-rounded,"SF Pro Rounded",system-ui,-apple-system,"Segoe UI",Roboto,sans-serif;
  --txt:system-ui,-apple-system,"Segoe UI",Roboto,Helvetica,Arial,sans-serif;
}
@media (prefers-color-scheme: dark){:root{
  --bg:#0E1511; --surface:#16201A; --ink:#E3EBE5; --ink2:#9DADA2; --line:#26332B;
  --leaf:#6DBF8A; --leaf-bg:#1D3426; --water:#5AA9E6; --water-bg:#15293A;
  --soil:#3E2B1F; --soil2:#4A3426; --warn:#F08A5D; --warn-bg:#3A2117; --on-water:#0B1E2C;
}}
*{box-sizing:border-box;margin:0;padding:0}
html{-webkit-text-size-adjust:100%}
body{font-family:var(--txt);font-size:1rem;line-height:1.45;background:var(--bg);color:var(--ink);
  padding:0 max(16px,env(safe-area-inset-right)) calc(96px + env(safe-area-inset-bottom)) max(16px,env(safe-area-inset-left))}
button,input{font:inherit;color:inherit}
:focus-visible{outline:3px solid var(--water);outline-offset:2px;border-radius:6px}
.wrap{max-width:760px;margin:0 auto}
.num{font-family:var(--num);font-variant-numeric:tabular-nums}

/* top bar */
.top{display:flex;align-items:center;justify-content:space-between;gap:12px;padding:calc(14px + env(safe-area-inset-top)) 0 10px}
.name{font-size:1.0625rem;font-weight:600;display:flex;align-items:center;gap:8px}
.name svg{color:var(--leaf)}
.conn{font-size:.8125rem;color:var(--ink2);display:flex;align-items:center;gap:6px;background:var(--surface);padding:5px 10px;border-radius:99px}
.conn i{width:7px;height:7px;border-radius:50%;background:var(--leaf)}
.conn.bad i{background:var(--warn)}

.banner{display:none;align-items:center;justify-content:space-between;gap:12px;background:var(--warn-bg);color:var(--warn);
  border-radius:var(--r-md);padding:12px 14px;font-size:.9375rem;margin-bottom:12px}
.banner.show{display:flex}
.banner button{background:none;border:0;font-weight:600;color:inherit;cursor:pointer;padding:6px 4px}

/* tabs: bottom bar on phone, segmented under header on wide screens */
.tabs{position:fixed;left:0;right:0;bottom:0;z-index:5;display:flex;justify-content:space-around;
  background:color-mix(in srgb,var(--surface) 88%,transparent);backdrop-filter:blur(16px);-webkit-backdrop-filter:blur(16px);
  border-top:1px solid var(--line);padding:6px 8px calc(6px + env(safe-area-inset-bottom))}
.tabs button{flex:1;max-width:140px;background:none;border:0;cursor:pointer;display:flex;flex-direction:column;align-items:center;gap:2px;
  font-size:.75rem;font-weight:500;color:var(--ink2);padding:6px 0;min-height:48px}
.tabs button[aria-selected="true"]{color:var(--leaf)}
@media (min-width:760px){
  body{padding-bottom:40px}
  .tabs{position:static;display:inline-flex;gap:2px;background:var(--line);border:0;border-radius:12px;padding:3px;backdrop-filter:none;margin:4px 0 18px}
  .tabs button{flex-direction:row;gap:6px;font-size:.875rem;padding:7px 18px;min-height:0;border-radius:9px;max-width:none}
  .tabs button[aria-selected="true"]{background:var(--surface);color:var(--ink)}
}
.view[hidden]{display:none}

/* hero */
.hero{display:grid;grid-template-columns:116px 1fr;gap:22px;align-items:stretch;background:var(--surface);border-radius:var(--r-lg);padding:20px}
.column{position:relative;border-radius:16px;overflow:hidden;min-height:228px;
  background:repeating-linear-gradient(170deg,var(--soil) 0 9px,var(--soil2) 9px 13px)}
.column .water{position:absolute;left:0;right:0;bottom:0;height:0;background:color-mix(in srgb,var(--water) 78%,transparent);
  transition:height .8s cubic-bezier(.2,.8,.2,1)}
.column .water::before{content:"";position:absolute;left:0;right:0;top:0;height:3px;background:color-mix(in srgb,#fff 45%,var(--water))}
.column .thr{position:absolute;left:0;right:0;height:0;border-top:2px dashed rgba(255,255,255,.9)}
.column .thr span{position:absolute;right:6px;top:-22px;font-size:.6875rem;font-weight:600;color:#fff;background:rgba(0,0,0,.45);padding:1px 6px;border-radius:6px}
.column .leaf{position:absolute;top:10px;left:50%;transform:translateX(-50%);color:#B8E0C2;opacity:.9}
.hero .say{display:flex;flex-direction:column;justify-content:space-between;gap:16px;min-width:0}
.big{font-size:3.5rem;line-height:1;font-weight:600;letter-spacing:-.02em}
.big small{font-size:1.375rem;font-weight:500;color:var(--ink2);margin-left:3px}
.headline{font-size:1.375rem;line-height:1.25;font-weight:600;margin-top:10px}
.explain{color:var(--ink2);font-size:.9375rem;margin-top:4px;max-width:36ch}
.pump{display:flex;align-items:center;gap:10px;border-top:1px solid var(--line);padding-top:14px;font-size:.9375rem}
.pump .ico{width:34px;height:34px;border-radius:10px;display:grid;place-items:center;background:var(--bg);color:var(--ink2);flex:none}
.pump.on .ico{background:var(--water);color:var(--on-water)}
.pump b{font-weight:600}
.pump .muted{color:var(--ink2)}
@media (max-width:420px){.hero{grid-template-columns:92px 1fr;gap:16px;padding:16px}.big{font-size:2.875rem}.headline{font-size:1.1875rem}}

/* metric rows */
h2{font-size:1.0625rem;font-weight:600;margin:26px 4px 10px}
.list{background:var(--surface);border-radius:var(--r-lg);overflow:hidden}
.row{display:grid;grid-template-columns:30px minmax(0,1fr) 72px auto;gap:12px;align-items:center;padding:14px 16px;border-top:1px solid var(--line)}
.row:first-child{border-top:0}
.row .ic{color:var(--ink2);display:grid;place-items:center}
.row .lab{font-weight:500}
.row .note{font-size:.8125rem;color:var(--ink2)}
.row .note.warn{color:var(--warn)}
.row .v{font-size:1.5rem;font-weight:600;text-align:right;min-width:78px}
.row .v small{font-size:.875rem;color:var(--ink2);font-weight:500;margin-left:2px}
.spark{width:72px;height:28px;display:block;overflow:visible}
.err{color:var(--warn);font-size:.875rem;font-weight:500}
.foot{font-size:.8125rem;color:var(--ink2);margin:10px 4px 0}

/* history */
.seg{display:inline-flex;background:var(--line);border-radius:10px;padding:2px;gap:2px}
.seg button{white-space:nowrap;border:0;background:none;padding:6px 14px;border-radius:8px;font-size:.875rem;font-weight:500;color:var(--ink2);cursor:pointer;min-height:32px}
.seg button[aria-pressed="true"]{background:var(--surface);color:var(--ink)}
.hhead{display:flex;justify-content:space-between;align-items:center;margin:4px 4px 12px}
.chart{background:var(--surface);border-radius:var(--r-lg);padding:16px;margin-bottom:12px}
.chart .ch{display:flex;justify-content:space-between;align-items:baseline;gap:12px;margin-bottom:10px}
.chart .ch b{font-weight:600}
.chart .read{font-size:.875rem;color:var(--ink2);text-align:right}
.plot{position:relative;height:120px;touch-action:pan-y;cursor:crosshair}
.plot svg{width:100%;height:100%;display:block;overflow:visible}
.plot .cur{position:absolute;top:0;bottom:0;width:1px;background:var(--ink2);opacity:0;pointer-events:none}
.plot:hover .cur,.plot.touch .cur{opacity:.6}
.axis{display:flex;justify-content:space-between;font-size:.75rem;color:var(--ink2);margin-top:6px}
.events{list-style:none}
.events li{display:flex;justify-content:space-between;gap:12px;padding:12px 16px;border-top:1px solid var(--line);font-size:.9375rem}
.events li:first-child{border-top:0}
.events .t{color:var(--ink2)}
.empty{padding:16px;color:var(--ink2);font-size:.9375rem}

/* care */
.group{background:var(--surface);border-radius:var(--r-lg);padding:4px 16px}
.item{display:flex;flex-wrap:wrap;justify-content:space-between;align-items:center;gap:10px 14px;padding:14px 0;border-top:1px solid var(--line)}
.item:first-child{border-top:0}
.item .d{font-size:.8125rem;color:var(--ink2);margin-top:2px}
.item.col{flex-direction:column;align-items:stretch}
.btn{border:0;border-radius:12px;padding:12px 18px;font-weight:600;cursor:pointer;min-height:44px}
.btn.primary{background:var(--water);color:var(--on-water)}
.btn.quiet{background:var(--bg);color:var(--ink)}
.btn.danger{background:var(--warn-bg);color:var(--warn)}
.btn:disabled{opacity:.5;cursor:default}
.waterbox{display:flex;gap:10px;align-items:center;flex-wrap:wrap}
.running{display:none;align-items:center;gap:12px;width:100%}
.running.show{display:flex}
.running .prog{flex:1;height:8px;border-radius:4px;background:var(--water-bg);overflow:hidden}
.running .prog i{display:block;height:100%;width:0;background:var(--water);transition:width 1s linear}
.switch{appearance:none;-webkit-appearance:none;width:51px;height:31px;border-radius:99px;background:var(--line);position:relative;cursor:pointer;flex:none;transition:background .2s}
.switch::after{content:"";position:absolute;top:2px;left:2px;width:27px;height:27px;border-radius:50%;background:#fff;box-shadow:0 1px 3px rgba(0,0,0,.25);transition:transform .2s}
.switch:checked{background:var(--leaf)}
.switch:checked::after{transform:translateX(20px)}
.slider{display:flex;align-items:center;gap:14px;margin-top:10px}
.slider input{flex:1;accent-color:var(--leaf);height:28px}
.slider output{font-weight:600;min-width:44px;text-align:right}
.calib{display:grid;grid-template-columns:1fr 1fr;gap:10px;margin-top:10px}
.calib .btn{width:100%}
.raw{font-size:.8125rem;color:var(--ink2);margin-top:8px}
dl.info{display:grid;grid-template-columns:auto 1fr;gap:10px 16px;padding:14px 0;font-size:.9375rem}
dl.info dt{color:var(--ink2)}
dl.info dd{text-align:right}

.toast{position:fixed;left:50%;bottom:calc(84px + env(safe-area-inset-bottom));transform:translate(-50%,20px);opacity:0;
  background:var(--ink);color:var(--bg);padding:10px 16px;border-radius:12px;font-size:.9375rem;font-weight:500;transition:.25s;pointer-events:none;z-index:9}
.toast.show{opacity:1;transform:translate(-50%,0)}
@media (min-width:760px){.toast{bottom:28px}}
.stale .live{opacity:.45}
.demo{font-size:.75rem;color:var(--ink2);text-align:center;margin-top:22px}
.warnbox{display:none;background:var(--warn-bg);color:var(--warn);border-radius:var(--r-md);padding:12px 14px;margin-bottom:12px}
.warnbox.show{display:block}
.warnbox b{display:flex;align-items:center;gap:8px;font-weight:600}
.warnbox ul{list-style:none;margin-top:6px;font-size:.9375rem}
.warnbox li{padding:3px 0 3px 26px}
.soils{display:flex;gap:8px;flex-wrap:wrap;margin-top:12px}
.chip{font-size:.8125rem;padding:4px 10px;border-radius:99px;background:var(--bg);color:var(--ink2)}
.chip b{color:var(--ink);font-weight:600}
.chip.bad{background:var(--warn-bg);color:var(--warn)}
.chip.bad b{color:var(--warn)}
.sens{list-style:none}
.sens li{display:grid;grid-template-columns:12px 1fr auto;gap:12px;align-items:center;padding:12px 0;border-top:1px solid var(--line);font-size:.9375rem}
.sens li:first-child{border-top:0}
.sens i{width:9px;height:9px;border-radius:50%;background:var(--leaf)}
.sens li.bad i{background:var(--warn)}
.sens li.bad .st{color:var(--warn)}
.sens .st{color:var(--ink2);font-size:.875rem;text-align:right}
.sens .sub{font-size:.8125rem;color:var(--ink2)}
.legend{display:flex;gap:14px;font-size:.8125rem;color:var(--ink2)}
.legend span{display:flex;align-items:center;gap:6px}
.legend i{width:14px;height:3px;border-radius:2px;display:inline-block}
body:not(.online) .online-only{display:none!important}
body.online .local-only{display:none!important}
.modetag{font-size:.75rem;font-weight:500;color:var(--ink2);border:1px solid var(--line);border-radius:99px;padding:2px 8px;margin-left:4px}
@media (prefers-reduced-motion:reduce){*{transition:none!important}}
</style>
</head>
<body>
<div class="wrap">
  <header class="top">
    <div class="name">
      <svg width="22" height="22" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true"><path d="M12 21v-9"/><path d="M12 12C12 7 8 4 3 4c0 5 4 8 9 8z"/><path d="M12 14c0-4 3-7 8-7 0 4-3 7-8 7z"/></svg>
      <span id="plantName">My plant</span><span class="modetag online-only">Online view</span>
    </div>
    <div class="conn" id="conn" role="status"><i></i><span id="connText">Connecting</span></div>
  </header>

  <div class="banner" id="banner" role="alert">
    <span id="bannerText">Can't reach the plant monitor. Check that it's powered and on Wi-Fi.</span>
    <button id="retry">Retry</button>
  </div>

  <nav class="tabs" role="tablist" aria-label="Sections">
    <button role="tab" aria-selected="true" aria-controls="v-now" data-v="now">
      <svg width="22" height="22" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true"><path d="M12 3s6 6.5 6 11a6 6 0 0 1-12 0c0-4.5 6-11 6-11z"/></svg>Now</button>
    <button role="tab" aria-selected="false" aria-controls="v-history" data-v="history">
      <svg width="22" height="22" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true"><path d="M3 17l5-5 4 3 8-8"/><path d="M3 21h18"/></svg>History</button>
    <button role="tab" aria-selected="false" aria-controls="v-care" data-v="care">
      <svg width="22" height="22" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true"><path d="M4 21v-7M4 10V3M12 21v-9M12 8V3M20 21v-5M20 12V3M1 14h6M9 8h6M17 16h6"/></svg>Care</button>
  </nav>

  <!-- NOW -->
  <section class="view live" id="v-now" role="tabpanel">
    <div class="warnbox" id="warnbox" role="alert">
      <b><svg width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true"><path d="M12 3l10 18H2z"/><path d="M12 10v4M12 17.5v.5"/></svg><span id="warnTitle">Sensor problem</span></b>
      <ul id="warnList"></ul>
    </div>
    <div class="hero">
      <div class="column" role="img" id="colLabel" aria-label="Soil moisture">
        <svg class="leaf" width="26" height="26" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true"><path d="M12 21v-9"/><path d="M12 12C12 7 8 4 3 4c0 5 4 8 9 8z"/><path d="M12 14c0-4 3-7 8-7 0 4-3 7-8 7z"/></svg>
        <div class="water" id="colWater"></div>
        <div class="thr" id="colThr" style="bottom:35%"><span id="colThrLabel">35%</span></div>
      </div>
      <div class="say">
        <div>
          <div class="big num"><span id="moist">--</span><small>%</small></div>
          <div class="headline" id="headline">Reading soil…</div>
          <p class="explain" id="explain">&nbsp;</p>
          <div class="soils" id="soils"></div>
        </div>
        <div class="pump" id="pump">
          <div class="ico" aria-hidden="true"><svg width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M12 3s6 6.5 6 11a6 6 0 0 1-12 0c0-4.5 6-11 6-11z"/></svg></div>
          <div><b id="pumpTitle">Pump off</b><div class="muted" id="pumpSub">&nbsp;</div></div>
        </div>
      </div>
    </div>

    <h2>Climate</h2>
    <div class="list">
      <div class="row">
        <div class="ic" aria-hidden="true"><svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M14 14.8V4a2 2 0 0 0-4 0v10.8a4 4 0 1 0 4 0z"/></svg></div>
        <div><div class="lab">Temperature</div><div class="note" id="tempN">&nbsp;</div></div>
        <svg class="spark" id="tempS" viewBox="0 0 72 28" preserveAspectRatio="none" aria-hidden="true"></svg>
        <div class="v num" id="temp">--</div>
      </div>
      <div class="row">
        <div class="ic" aria-hidden="true"><svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M17.5 19H8a5 5 0 1 1 1.6-9.7A6 6 0 0 1 21 12.5 3.5 3.5 0 0 1 17.5 19z"/></svg></div>
        <div><div class="lab">Air humidity</div><div class="note" id="humN">&nbsp;</div></div>
        <svg class="spark" id="humS" viewBox="0 0 72 28" preserveAspectRatio="none" aria-hidden="true"></svg>
        <div class="v num" id="hum">--</div>
      </div>
      <div class="row">
        <div class="ic" aria-hidden="true"><svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round"><circle cx="12" cy="12" r="4"/><path d="M12 2v2M12 20v2M4.9 4.9l1.4 1.4M17.7 17.7l1.4 1.4M2 12h2M20 12h2M4.9 19.1l1.4-1.4M17.7 6.3l1.4-1.4"/></svg></div>
        <div><div class="lab">Light</div><div class="note" id="luxN">&nbsp;</div></div>
        <svg class="spark" id="luxS" viewBox="0 0 72 28" preserveAspectRatio="none" aria-hidden="true"></svg>
        <div class="v num" id="lux">--</div>
      </div>
    </div>
    <p class="foot" id="updated">Waiting for first reading</p>
  </section>

  <!-- HISTORY -->
  <section class="view" id="v-history" role="tabpanel" hidden>
    <div class="hhead">
      <h2 style="margin:0">Last <span id="rangeLabel">24 hours</span></h2>
      <div class="seg" role="group" aria-label="Time range">
        <button aria-pressed="false" data-r="6">6 h</button>
        <button aria-pressed="true" data-r="24">24 h</button>
      </div>
    </div>
    <div id="charts"></div>
    <h2>Watering log</h2>
    <ul class="list events" id="events"><li class="empty">No watering yet in this period.</li></ul>
  </section>

  <!-- CARE -->
  <section class="view" id="v-care" role="tabpanel" hidden>
    <div class="online-only">
      <div class="group" style="margin-top:4px">
        <div class="item col">
          <div><b style="font-weight:600">Read-only online view</b>
          <div class="d" style="font-size:.9375rem;margin-top:4px">Watering and settings work only on your home network. Open <span class="num">http://plant.local</span> there.</div></div>
        </div>
      </div>
    </div>
    <div class="local-only">
    <h2 style="margin-top:4px">Water now</h2>
    <div class="group">
      <div class="item col">
        <div class="waterbox" id="waterIdle">
          <div class="seg" role="group" aria-label="Duration">
            <button aria-pressed="false" data-s="5">5 s</button>
            <button aria-pressed="true" data-s="10">10 s</button>
            <button aria-pressed="false" data-s="20">20 s</button>
          </div>
          <button class="btn primary" id="waterBtn">Water for 10 s</button>
        </div>
        <div class="running" id="waterRun">
          <div class="prog"><i id="runBar"></i></div>
          <span class="num" id="runLeft">10 s</span>
          <button class="btn danger" id="stopBtn">Stop</button>
        </div>
      </div>
    </div>

    <h2>Automatic watering</h2>
    <div class="group">
      <div class="item">
        <div><div>Water automatically</div><div class="d">Runs the pump when soil gets too dry</div></div>
        <input type="checkbox" class="switch" id="auto" role="switch" aria-label="Water automatically" checked>
      </div>
      <div class="item col">
        <div><div>Start watering below</div><div class="d">Most houseplants: 30–40 %. Cacti: 15–20 %.</div></div>
        <div class="slider">
          <input type="range" id="thr" min="5" max="80" step="1" value="35" aria-label="Moisture threshold">
          <output class="num" id="thrOut" for="thr">35 %</output>
        </div>
      </div>
      <div class="item">
        <div><div>Max. pump time</div><div class="d">Safety stop if the sensor fails</div></div>
        <div class="seg" role="group" aria-label="Max pump time" id="maxSeg">
          <button aria-pressed="false" data-m="15">15 s</button>
          <button aria-pressed="true" data-m="30">30 s</button>
          <button aria-pressed="false" data-m="60">60 s</button>
        </div>
      </div>
      <div class="item"><span class="d" id="saveState">All changes saved</span><button class="btn quiet" id="saveBtn" disabled>Save</button></div>
    </div>

    </div>
    <h2>Sensors</h2>
    <div class="group"><ul class="sens" id="sensList"><li><i></i><span>Checking sensors…</span><span></span></li></ul></div>

    <div class="local-only">
    <h2>Soil sensor calibration</h2>
    <div class="group">
      <div class="item col">
        <div class="d">Do this for both sensors at once. Hold them in dry air and press "Set dry". Then put them in a glass of water (up to the line on the sensor) and press "Set wet".</div>
        <div class="calib">
          <button class="btn quiet" data-cal="dry">Set dry</button>
          <button class="btn quiet" data-cal="wet">Set wet</button>
        </div>
        <div class="raw num" id="rawInfo">&nbsp;</div>
      </div>
    </div>

    </div>
    <h2>Device</h2>
    <div class="group">
      <dl class="info num">
        <dt>Board</dt><dd id="board">XIAO ESP32-C3</dd>
        <dt class="online-only">Data source</dt><dd class="online-only" id="srcInfo">--</dd>
        <dt class="online-only">Last upload</dt><dd class="online-only" id="lastUp">--</dd>
        <dt class="local-only">Online upload</dt><dd class="local-only" id="cloud">--</dd>
        <dt class="local-only">Wi-Fi</dt><dd class="local-only" id="wifiMode">--</dd>
        <dt class="local-only">Wi-Fi signal</dt><dd class="local-only" id="rssi">--</dd>
        <dt class="local-only">Running for</dt><dd class="local-only" id="uptime">--</dd>
        <dt class="local-only">IP address</dt><dd class="local-only" id="ip">--</dd>
        <dt class="local-only">Firmware</dt><dd class="local-only" id="fw">--</dd>
      </dl>
    </div>
  </section>

  <p class="demo" id="demoNote">Preview with simulated data</p>
</div>
<div class="toast" id="toast" role="status" aria-live="polite"></div>

<script>
/* ===== Config ===== */
const DEMO = false;          // false on the ESP and online
/* Online (https) the page reads ThingSpeak. Set the channel here, or add ?ch=123456 to the address. */
const params = new URLSearchParams(location.search);
const TS_CHANNEL  = params.get('ch')  || '';     // your ThingSpeak channel ID
const TS_READ_KEY = params.get('key') || '';     // only needed for a private channel
const UPLOAD_S = 60;                              // must match UPLOAD_MS in the firmware
const MODE = DEMO ? (params.has('online') ? 'demo-online' : 'demo')
                  : (location.protocol === 'https:' ? 'online' : 'local');
const ONLINE = MODE === 'online' || MODE === 'demo-online';
const POLL_MS = ONLINE ? 20000 : 3000;
const STALE_MS = ONLINE ? 70000 : 10000;          // how long until "can't reach" shows
const DEVICE_STALE_MS = (3 * UPLOAD_S + 60) * 1000;
if (ONLINE) document.body.classList.add('online');
const SOIL_PINS = ['A0', 'A1'];

const $ = id => document.getElementById(id);
const fmtTime = t => new Date(t).toLocaleTimeString([], {hour:'2-digit', minute:'2-digit'});
const IDEAL = {temp:[18,25], hum:[40,60]};

/* ===== API ===== */
async function get(url){ const r = await fetch(url, {cache:'no-store'}); if(!r.ok) throw r.status; return r.json(); }
async function post(url, data){
  const r = await fetch(url, {method:'POST', body:new URLSearchParams(data)});
  if(!r.ok) throw r.status; return r.json();
}
/* The ESP has no clock, so it sends ages in seconds. Convert them to times here. */
const fromEsp = d => ({...d, time: Date.now(),
  lastWater: d.lastWaterAgo == null ? null : Date.now() - d.lastWaterAgo * 1000});
const histFromEsp = h => ({...h, end: Date.now(),
  events: h.events.map(e => ({t: Date.now() - e.ago * 1000, s: e.s, manual: !!e.m}))});
/* ===== Online: read the public ThingSpeak channel (read-only) =====
   field1 soil 1 %, field2 soil 2 %, field3 °C, field4 %RH, field5 lux,
   field6 manual watering s, field7 auto watering s, field8 flags (see firmware) */
const tsUrl = (path, q) => `https://api.thingspeak.com/channels/${TS_CHANNEL}/${path}?${q}${TS_READ_KEY ? '&api_key=' + TS_READ_KEY : ''}`;
const tsGet = url => MODE === 'demo-online' ? demoTs(url) : get(url);
const num = v => v == null || v === '' ? null : +v;
function decode(f){
  const flags = num(f.field8) || 0, bit = n => !!((flags >> n) & 1);
  return {t: Date.parse(f.created_at), m1: num(f.field1), m2: num(f.field2), temp: num(f.field3), hum: num(f.field4),
    lux: num(f.field5), man: num(f.field6) || 0, aut: num(f.field7) || 0,
    s1: bit(0), s2: bit(1), sht: bit(2), tsl: bit(3), sat: bit(4), autoOn: bit(5), disagree: bit(6),
    cal1: bit(7), cal2: bit(8), thr: (flags >> 9) & 127};
}
let onlineLastWater = null;
async function onlineStatus(){
  if (!TS_CHANNEL && MODE === 'online') throw 'nochannel';
  const r = await tsGet(tsUrl('feeds.json', 'results=1'));
  if (!r.feeds || !r.feeds.length) throw 'empty';
  const e = decode(r.feeds[r.feeds.length - 1]);
  const soil = [{ok: e.s1 && e.m1 != null, pct: e.m1 == null ? null : Math.round(e.m1), cal: e.cal1},
                {ok: e.s2 && e.m2 != null, pct: e.m2 == null ? null : Math.round(e.m2), cal: e.cal2}];
  const ok = soil.filter(x => x.ok);
  return {moist: ok.length ? Math.round(ok.reduce((a, x) => a + x.pct, 0) / ok.length) : null,
    thr: e.thr, auto: e.autoOn, maxRun: 30, soil, disagree: e.disagree,
    sht: e.sht ? 'ok' : 'missing', light: !e.tsl ? 'missing' : e.sat ? 'saturated' : 'ok',
    temp: e.temp, hum: e.hum, lux: e.lux, pump: {on: false, left: 0}, soakLeft: 0,
    lastWater: onlineLastWater, time: e.t, chName: r.channel && r.channel.name};
}
async function onlineHistory(h){
  if (!TS_CHANNEL && MODE === 'online') throw 'nochannel';
  const r = await tsGet(tsUrl('feeds.json', `minutes=${h * 60}&results=8000`));
  const step = 300, n = h * 3600 / step, end = Date.now(), t0 = end - (n - 1) * step * 1000;
  const keys = ['m1', 'm2', 'temp', 'hum', 'lux'], sum = {}, cnt = {};
  keys.forEach(k => { sum[k] = new Array(n).fill(0); cnt[k] = new Array(n).fill(0); });
  const events = []; let thr = 35;
  (r.feeds || []).forEach(f => {
    const e = decode(f), i = Math.round((e.t - t0) / (step * 1000));
    thr = e.thr || thr;
    if (e.man > 0) events.push({t: e.t, s: e.man, manual: true});
    if (e.aut > 0) events.push({t: e.t, s: e.aut, manual: false});
    if (i < 0 || i >= n) return;
    keys.forEach(k => { const v = (k === 'm1' && !e.s1) || (k === 'm2' && !e.s2) ? null : e[k];
      if (v != null && !isNaN(v)) { sum[k][i] += v; cnt[k][i]++; } });
  });
  const out = {step, end, thr, events};
  keys.forEach(k => out[k] = sum[k].map((v, i) => cnt[k][i] ? v / cnt[k][i] : null));
  if (events.length) onlineLastWater = events[events.length - 1].t;
  return out;
}

const api = {
  status:   () => ONLINE ? onlineStatus()   : DEMO ? demo.status()   : get('/api/status').then(fromEsp),
  history:  h  => ONLINE ? onlineHistory(h) : DEMO ? demo.history(h) : get('/api/history?h=' + h).then(histFromEsp),
  water:    s  => DEMO ? demo.water(s)      : post('/api/water', {s}),
  stop:     () => DEMO ? demo.stop()        : post('/api/stop', {}),
  settings: o  => DEMO ? demo.settings(o)   : post('/api/settings', o),
  calibrate:p  => DEMO ? demo.calibrate(p)  : post('/api/calibrate', {p}),
};

/* ===== State ===== */
let S = null, lastOk = 0, hist = null, range = 24, dur = 10, maxRun = 30, dirty = false;

/* ===== Sensor warnings ===== */
function problems(d){
  const p = [], bad = d.soil.map((s, i) => s.ok ? null : i).filter(i => i != null);
  if (bad.length === 2) p.push('No soil sensor is working. Automatic watering is paused. Check the cables on A0 and A1.');
  else if (bad.length === 1) {
    const i = bad[0];
    p.push(`Soil sensor ${i + 1} (${SOIL_PINS[i]}) isn't connected or reads nonsense. Using sensor ${2 - i} only.`);
  }
  if (d.disagree) p.push(`The two soil sensors differ by ${Math.abs(d.soil[0].pct - d.soil[1].pct)} %. Check that both are pushed fully into the soil.`);
  if (d.sht !== 'ok') p.push('Temperature and humidity sensor (SHT3x) not found. Check SDA (D4), SCL (D5) and 3.3 V.');
  if (d.light === 'missing') p.push('Light sensor (TSL2591) not found. Check SDA (D4), SCL (D5) and 3.3 V.');
  if (d.soil.some(s => s.ok && !s.cal)) p.push('Soil sensors use default calibration, so the % values are rough. Calibrate them in Care.');
  return p;
}
function renderWarnings(d){
  const p = problems(d);
  $('warnbox').classList.toggle('show', p.length > 0);
  $('warnTitle').textContent = p.length === 1 ? 'Check one thing' : `Check ${p.length} things`;
  $('warnList').innerHTML = p.map(t => `<li>${t}</li>`).join('');
}
function renderSensorList(d){
  const li = (ok, name, sub, st) => `<li class="${ok ? '' : 'bad'}"><i></i><div>${name}<div class="sub num">${sub}</div></div><span class="st">${st}</span></li>`;
  let h = d.soil.map((s, i) => li(s.ok, `Soil sensor ${i + 1}`, ONLINE ? `Pin ${SOIL_PINS[i]}` : `Pin ${SOIL_PINS[i]}, raw ${s.raw}`, s.ok ? (s.cal ? 'Working' : 'Not calibrated') : 'Not connected')).join('');
  h += li(d.sht === 'ok', 'Temperature and humidity', 'SHT3x on I²C', d.sht === 'ok' ? 'Working' : 'Not found');
  h += li(d.light !== 'missing', 'Light', 'TSL2591 on I²C', d.light === 'ok' ? 'Working' : d.light === 'saturated' ? 'Too bright' : 'Not found');
  $('sensList').innerHTML = h;
  if (!ONLINE) $('rawInfo').innerHTML = d.soil.map((s, i) =>
    `Sensor ${i + 1}: raw ${s.ok ? s.raw : '--'}, dry point ${s.dry}, wet point ${s.wet}`).join('<br>');
}

/* ===== Now ===== */
function renderNow(d){
  const m = d.moist, thr = d.thr;
  $('moist').textContent = m == null ? '--' : m;
  $('colWater').style.height = (m ?? 0) + '%';
  $('colThr').style.bottom = thr + '%';
  $('colThrLabel').textContent = thr + '%';
  $('colLabel').setAttribute('aria-label', `Soil moisture ${m ?? 'unknown'} percent, watering threshold ${thr} percent`);

  let head, exp;
  if (m == null)             { head = "No soil reading"; exp = "Both soil sensors are not responding. Automatic watering is paused."; }
  else if (d.pump.on)        { head = "Watering now"; exp = "The pump stops by itself when the time is up."; }
  else if (m < thr)          { head = "Soil is dry"; exp = !d.auto ? "Automatic watering is off. Water it from Care."
                               : d.soakLeft > 0 ? `Letting the last watering soak in. Next check in ${Math.ceil(d.soakLeft/60)} min.`
                               : "Watering starts within a few seconds."; }
  else if (m < thr + 10)     { head = "Soil is getting dry"; exp = `Watering starts at ${thr} %.`; }
  else if (m > 85)           { head = "Soil is very wet"; exp = "Make sure the pot can drain."; }
  else                       { head = "Soil is moist"; exp = `Nothing to do. Watering starts at ${thr} %.`; }
  $('headline').textContent = head;
  $('explain').textContent = exp;

  $('soils').innerHTML = d.soil.map((s, i) => s.ok
    ? `<span class="chip">Sensor ${i + 1} <b class="num">${s.pct} %</b></span>`
    : `<span class="chip bad">Sensor ${i + 1} <b>offline</b></span>`).join('');

  $('pump').className = d.pump.on ? 'pump on' : 'pump';
  $('pumpTitle').textContent = d.pump.on ? 'Pump running' : (d.auto ? 'Pump off' : 'Pump off, automatic off');
  $('pumpSub').textContent = d.pump.on ? `${d.pump.left} s left`
    : d.lastWater ? `Last watered ${ago(d.lastWater)}` : ONLINE ? `Not watered in the last ${range} h` : 'Not watered since start';

  row('temp', d.sht === 'ok' ? d.temp : null, v => v.toFixed(1), '°C', IDEAL.temp, ['Too cold','Too warm'], '18–25 °C is ideal', 'SHT3x not found');
  row('hum',  d.sht === 'ok' ? d.hum : null,  v => Math.round(v), '%', IDEAL.hum, ['Too dry','Too humid'], '40–60 % is ideal', 'SHT3x not found');
  const lux = d.light === 'missing' ? null : d.lux;
  $('lux').innerHTML = lux == null ? '<span class="err">Offline</span>' : `${Math.round(lux)}<small>lux</small>`;
  $('luxN').textContent = lux == null ? 'TSL2591 not found' : d.light === 'saturated' ? 'Too bright to measure exactly'
    : lux < 100 ? 'Dark' : lux < 1000 ? 'Indirect light' : 'Bright light';
  $('luxN').className = lux == null || d.light === 'saturated' ? 'note warn' : 'note';
  $('updated').textContent = ONLINE
    ? `Measured at ${fmtTime(d.time)} (${ago(d.time)}). New data every ${UPLOAD_S} s.`
    : `Updated ${new Date(d.time).toLocaleTimeString()}`;

  renderWarnings(d);
  renderSensorList(d);
  if (ONLINE){
    $('srcInfo').textContent = MODE === 'demo-online' ? 'ThingSpeak (demo)' : `ThingSpeak channel ${TS_CHANNEL}`;
    $('lastUp').textContent = ago(d.time);
  } else {
    const c = d.cloud || {};
    $('cloud').textContent = !c.on ? 'Off (no write key set)' : c.ok ? `OK, ${c.ago} s ago` : `Not working: ${c.err || 'no upload yet'}`;
  }
  $('wifiMode').textContent = d.ap ? 'Own network (no router found)' : 'Connected to router';
  $('rssi').textContent = d.ap || d.rssi == null ? '--' : `${d.rssi} dBm (${d.rssi > -60 ? 'good' : d.rssi > -75 ? 'fair' : 'weak'})`;
  $('uptime').textContent = dur2(d.uptime);
  $('ip').textContent = d.ip || location.hostname || '--';
  $('fw').textContent = d.fw || '--';
  if (!dirty){ $('auto').checked = d.auto; $('thr').value = thr; $('thrOut').textContent = thr + ' %'; setSeg($('maxSeg'), 'm', d.maxRun); maxRun = d.maxRun; }
  renderPumpControls(d.pump);
}
function row(id, v, f, unit, [lo, hi], words, ok, missing){
  const el = $(id), n = $(id + 'N');
  if (v == null){ el.innerHTML = '<span class="err">Offline</span>'; n.textContent = missing; n.className = 'note warn'; return; }
  el.innerHTML = `${f(v)}<small>${unit}</small>`;
  if (v < lo){ n.textContent = `${words[0]}. ${ok}`; n.className = 'note warn'; }
  else if (v > hi){ n.textContent = `${words[1]}. ${ok}`; n.className = 'note warn'; }
  else { n.textContent = ok; n.className = 'note'; }
}
function ago(t){ const s = (Date.now() - t) / 1000;
  if (s < 90) return 'just now'; if (s < 3600) return Math.round(s/60) + ' min ago';
  if (s < 86400) return Math.round(s/3600) + ' h ago'; return Math.round(s/86400) + ' days ago'; }
function dur2(s){ if (s == null) return '--'; const d = Math.floor(s/86400), h = Math.floor(s%86400/3600), m = Math.floor(s%3600/60);
  return d ? `${d} d ${h} h` : h ? `${h} h ${m} min` : `${m} min`; }

/* ===== Charts (no library) ===== */
const css = n => getComputedStyle(document.documentElement).getPropertyValue(n).trim();
function pathFor(vals, W, H, lo, hi, pad){
  let d = '', pen = false;
  vals.forEach((v, i) => {
    if (v == null){ pen = false; return; }
    const x = vals.length < 2 ? W/2 : i * W / (vals.length - 1);
    const y = H - pad - (v - lo) / (hi - lo || 1) * (H - 2*pad);
    d += (pen ? 'L' : 'M') + x.toFixed(1) + ' ' + y.toFixed(1); pen = true;
  });
  return d;
}
function spark(svg, vals, color){
  const v = vals.filter(x => x != null); if (v.length < 2){ svg.innerHTML = ''; return; }
  const lo = Math.min(...v), hi = Math.max(...v), pad = (hi - lo) * .15 || 1;
  svg.innerHTML = `<path d="${pathFor(vals, 72, 28, lo - pad, hi + pad, 2)}" fill="none" stroke="${color}" stroke-width="1.75" stroke-linejoin="round" stroke-linecap="round" vector-effect="non-scaling-stroke"/>`;
}
const SERIES = [
  {keys:['m1','m2'], name:'Soil moisture', unit:'%', f:v=>Math.round(v), color:'--water', fixed:[0,100], soil:true},
  {keys:['temp'], name:'Temperature',  unit:'°C',  f:v=>v.toFixed(1),  color:'--warn', band:IDEAL.temp},
  {keys:['hum'],  name:'Air humidity', unit:'%',   f:v=>Math.round(v), color:'--leaf', band:IDEAL.hum},
  {keys:['lux'],  name:'Light',        unit:'lux', f:v=>Math.round(v), color:'--ink2'},
];
function renderHistory(h){
  const box = $('charts'); box.innerHTML = '';
  const n = h.m1.length, t0 = h.end - (n - 1) * h.step * 1000, at = i => fmtTime(t0 + i * h.step * 1000);
  SERIES.forEach(s => {
    const all = s.keys.flatMap(k => h[k]).filter(x => x != null);
    const c = document.createElement('div'); c.className = 'chart';
    if (!all.length){ c.innerHTML = `<div class="ch"><b>${s.name}</b></div><div class="empty" style="padding:0">No data in this period. The sensor may be offline.</div>`; box.append(c); return; }
    let lo = s.fixed ? s.fixed[0] : Math.min(...all), hi = s.fixed ? s.fixed[1] : Math.max(...all);
    if (s.band){ lo = Math.min(lo, s.band[0]); hi = Math.max(hi, s.band[1]); }
    if (!s.fixed){ const p = (hi - lo) * .1 || 1; lo -= p; hi += p; }
    const W = 600, H = 120, y = val => H - 4 - (val - lo) / (hi - lo) * (H - 8);
    const col = css(s.color);
    let svg = '';
    if (s.band) svg += `<rect x="0" width="${W}" y="${y(s.band[1])}" height="${y(s.band[0]) - y(s.band[1])}" fill="${css('--leaf')}" opacity=".10"/>`;
    if (s.soil) svg += `<line x1="0" x2="${W}" y1="${y(h.thr)}" y2="${y(h.thr)}" stroke="${css('--ink2')}" stroke-dasharray="2 4" opacity=".8" vector-effect="non-scaling-stroke"/>`;
    s.keys.forEach((k, j) => {
      svg += `<path d="${pathFor(h[k], W, H, lo, hi, 4)}" fill="none" stroke="${col}" stroke-width="2" ${j ? 'stroke-dasharray="6 4" opacity=".75"' : ''} stroke-linejoin="round" vector-effect="non-scaling-stroke"/>`;
    });
    const mn = Math.min(...all), mx = Math.max(...all), def = `Low ${s.f(mn)}, high ${s.f(mx)} ${s.unit}`;
    const legend = s.soil ? `<div class="legend" style="margin-bottom:8px"><span><i style="background:${col}"></i>Sensor 1</span><span><i style="background:repeating-linear-gradient(90deg,${col} 0 5px,transparent 5px 8px)"></i>Sensor 2</span><span><i style="background:repeating-linear-gradient(90deg,${css('--ink2')} 0 2px,transparent 2px 5px)"></i>Threshold</span></div>` : '';
    c.innerHTML = `
      <div class="ch"><b>${s.name}</b><span class="read num" data-def="${def}">${def}</span></div>${legend}
      <div class="plot" role="img" aria-label="${s.name}, last ${range} hours, between ${s.f(mn)} and ${s.f(mx)} ${s.unit}">
        <svg viewBox="0 0 ${W} ${H}" preserveAspectRatio="none">${svg}</svg><div class="cur"></div>
      </div>
      <div class="axis"><span>${at(0)}</span><span>${at((n - 1) / 2)}</span><span>Now</span></div>`;
    const plot = c.querySelector('.plot'), cur = c.querySelector('.cur'), read = c.querySelector('.read');
    const move = e => {
      const r = plot.getBoundingClientRect(), fx = Math.min(1, Math.max(0, (e.clientX - r.left) / r.width));
      const i = Math.round(fx * (n - 1));
      cur.style.left = (i / Math.max(1, n - 1) * 100) + '%';
      const parts = s.keys.map((k, j) => { const v = h[k][i]; const lab = s.keys.length > 1 ? `S${j + 1} ` : '';
        return v == null ? `${lab}--` : `${lab}${s.f(v)} ${s.unit}`; });
      read.textContent = `${parts.join(', ')} at ${at(i)}`;
    };
    plot.addEventListener('pointermove', move);
    plot.addEventListener('pointerdown', e => { plot.classList.add('touch'); move(e); });
    plot.addEventListener('pointerleave', () => { plot.classList.remove('touch'); read.textContent = read.dataset.def; });
    box.append(c);
  });
  $('events').innerHTML = h.events.length ? h.events.slice().reverse().map(e =>
    `<li><span>${e.manual ? 'Watered by hand' : 'Watered automatically'}, ${e.s} s</span><span class="t num">${fmtTime(e.t)}</span></li>`).join('')
    : '<li class="empty">No watering yet in this period.</li>';
}
async function loadHistory(){
  try {
    hist = await api.history(range);
    renderHistory(hist);
    if (ONLINE && S){ S.lastWater = onlineLastWater; renderNow(S); }
    const last = k => hist[k].slice(-Math.round(3600 / hist.step * 2));   // last 2 h
    spark($('tempS'), last('temp'), css('--warn'));
    spark($('humS'),  last('hum'),  css('--leaf'));
    spark($('luxS'),  last('lux'),  css('--ink2'));
  } catch(e) { $('charts').innerHTML = '<div class="chart empty">Couldn\'t load history. It loads again in a moment.</div>'; }
}

/* ===== Pump controls ===== */
let runTotal = 0;
function renderPumpControls(p){
  $('waterIdle').style.display = p.on ? 'none' : 'flex';
  $('waterRun').classList.toggle('show', p.on);
  if (p.on){
    runTotal = Math.max(runTotal, p.left);
    $('runLeft').textContent = p.left + ' s';
    $('runBar').style.width = (100 - p.left / (runTotal || 1) * 100) + '%';
  } else runTotal = 0;
}
$('waterBtn').onclick = async () => {
  $('waterBtn').disabled = true;
  try { await api.water(dur); toast(`Watering for ${Math.min(dur, maxRun)} s`); runTotal = dur; await poll(); }
  catch(e){ toast("Couldn't start the pump. Try again."); }
  $('waterBtn').disabled = false;
};
$('stopBtn').onclick = async () => {
  try { await api.stop(); toast('Pump stopped'); await poll(); } catch(e){ toast("Couldn't stop the pump. Try again."); }
};
document.querySelectorAll('[data-s]').forEach(b => b.onclick = () => {
  dur = +b.dataset.s; setSeg(b.parentNode, 's', dur); $('waterBtn').textContent = `Water for ${dur} s`;
});

/* ===== Settings ===== */
function setSeg(group, key, val){ group.querySelectorAll('button').forEach(b => b.setAttribute('aria-pressed', +b.dataset[key] === +val)); }
function markDirty(){ dirty = true; $('saveBtn').disabled = false; $('saveState').textContent = 'Unsaved changes'; }
$('thr').oninput = e => { $('thrOut').textContent = e.target.value + ' %'; $('colThr').style.bottom = e.target.value + '%'; $('colThrLabel').textContent = e.target.value + '%'; markDirty(); };
$('auto').onchange = markDirty;
document.querySelectorAll('[data-m]').forEach(b => b.onclick = () => { maxRun = +b.dataset.m; setSeg($('maxSeg'), 'm', maxRun); markDirty(); });
$('saveBtn').onclick = async () => {
  $('saveBtn').disabled = true;
  try { await api.settings({thr: $('thr').value, auto: $('auto').checked ? 1 : 0, max: maxRun});
        dirty = false; $('saveState').textContent = 'All changes saved'; toast('Settings saved'); poll(); }
  catch(e){ $('saveBtn').disabled = false; toast("Couldn't save. Try again."); }
};
document.querySelectorAll('[data-cal]').forEach(b => b.onclick = async () => {
  const what = b.dataset.cal === 'dry' ? 'Dry' : 'Wet';
  try {
    const r = await api.calibrate(b.dataset.cal);
    const done = r.done || [];
    toast(done.length === 2 ? `${what} point saved for both sensors` : `${what} point saved for sensor ${done[0]} only. The other one is offline.`);
    poll();
  } catch(e){ toast("Couldn't calibrate. No soil sensor is working."); }
});

/* ===== Tabs ===== */
document.querySelectorAll('.tabs button').forEach(b => b.onclick = () => {
  document.querySelectorAll('.tabs button').forEach(x => x.setAttribute('aria-selected', x === b));
  document.querySelectorAll('.view').forEach(v => v.hidden = v.id !== 'v-' + b.dataset.v);
  if (b.dataset.v === 'history' && hist) renderHistory(hist);
  scrollTo({top:0});
});
document.querySelectorAll('[data-r]').forEach(b => b.onclick = () => {
  range = +b.dataset.r; setSeg(b.parentNode, 'r', range); $('rangeLabel').textContent = range + ' hours'; loadHistory();
});

/* ===== Polling, stale and offline ===== */
async function poll(){
  try { S = await api.status(); lastOk = Date.now(); lastErr = null; renderNow(S); health(); }
  catch(e){ lastErr = typeof e === 'string' ? e : 'net'; health(); }
}
let lastErr = null;
function health(){
  const age = Date.now() - lastOk, stale = !lastOk || age > STALE_MS;
  const devStale = ONLINE && S && Date.now() - S.time > DEVICE_STALE_MS;
  const bad = stale || devStale;
  $('conn').classList.toggle('bad', bad);
  $('connText').textContent = !lastOk && !lastErr ? 'Connecting' : stale ? 'Offline' : devStale ? 'Device offline' : 'Live';
  document.body.classList.toggle('stale', bad && !!lastOk);
  $('banner').classList.toggle('show', bad && (!!lastOk || !!lastErr));
  let msg;
  if (lastErr === 'nochannel') msg = 'No channel set. Add ?ch=YOUR_CHANNEL_ID to the address.';
  else if (lastErr === 'empty') msg = "The channel has no data yet. Check the write key in the firmware.";
  else if (stale) msg = ONLINE ? "Can't reach ThingSpeak. Check your internet connection."
                               : `No data for ${Math.round(age/1000)} s. Check that the plant monitor is powered and on Wi-Fi.`;
  else if (devStale) msg = `The plant monitor hasn't sent data since ${fmtTime(S.time)}. It may be off or without internet.`;
  if (msg) $('bannerText').textContent = msg;
}
$('retry').onclick = poll;
let tt; function toast(t){ const el = $('toast'); el.textContent = t; el.classList.add('show'); clearTimeout(tt); tt = setTimeout(() => el.classList.remove('show'), 2600); }

/* ===== Demo backend (preview only): light sensor is "missing" to show the warnings ===== */
const demo = (() => {
  const step = 300, N = 288, now = Date.now();
  let st = {thr:35, auto:true, maxRun:30, pumpEnd:0, lastWater: now - 5.2*3600e3,
            soil:[{m:48, dry:3200, wet:1350, cal:true}, {m:52, dry:3150, wet:1400, cal:true}]};
  const H = {m1:[], m2:[], temp:[], hum:[], lux:[], events:[]};
  let m = 70;
  for (let i = 0; i < N; i++){
    const t = now - (N - 1 - i) * step * 1000, hr = new Date(t).getHours() + new Date(t).getMinutes()/60;
    const day = Math.max(0, Math.sin((hr - 6) / 14 * Math.PI));
    m -= 0.12 + day * 0.18 + Math.random()*0.05;
    if (m < st.thr){ m += 32; H.events.push({t, s:10, manual:false}); }
    if (i === 200){ m = Math.min(90, m + 8); H.events.push({t, s:5, manual:true}); }
    H.m1.push(+m.toFixed(1)); H.m2.push(+(m + 4 + Math.sin(i / 20) * 2).toFixed(1));
    H.temp.push(+(19.5 + day * 5.5 + (Math.random() - .5) * .4).toFixed(1));
    H.hum.push(+(56 - day * 13 + (Math.random() - .5) * 2).toFixed(1));
    H.lux.push(i > 230 ? null : Math.round(day * 1800 * (0.8 + Math.random() * .3) + 5));   // light sensor lost 4.5 h ago
  }
  st.soil[0].m = m; st.soil[1].m = m + 4;
  st.lastWater = H.events.length ? H.events[H.events.length-1].t : st.lastWater;
  const wait = v => new Promise(r => setTimeout(() => r(v), 120));
  return {
    status(){
      const t = Date.now(), on = st.pumpEnd > t;
      st.soil.forEach(s => s.m = on ? Math.min(92, s.m + 1.4) : Math.max(5, s.m - 0.25));
      const avg = Math.round((st.soil[0].m + st.soil[1].m) / 2);
      if (!on && st.auto && avg < st.thr){ st.pumpEnd = t + 10000; st.lastWater = t; H.events.push({t, s:10, manual:false}); }
      const hr = new Date().getHours(), day = Math.max(0, Math.sin((hr - 6) / 14 * Math.PI));
      const soil = st.soil.map(s => ({ok:true, cal:s.cal, pct:Math.round(s.m), dry:s.dry, wet:s.wet,
        raw:Math.round(s.dry - s.m / 100 * (s.dry - s.wet))}));
      return wait({moist:avg, thr:st.thr, auto:st.auto, maxRun:st.maxRun, soil, disagree:false,
        sht:'ok', light:'missing', temp:19.5 + day * 5.5 + (Math.random() - .5) * .3, hum:56 - day * 13 + (Math.random() - .5), lux:null,
        pump:{on: st.pumpEnd > t, left: Math.max(0, Math.ceil((st.pumpEnd - t) / 1000))}, soakLeft:0,
        lastWater:st.lastWater, rssi:-63, ap:false, uptime:Math.round((t - now) / 1000) + 3 * 86400 + 5 * 3600,
        ip:'192.168.0.42', fw:'1.2.0', board:'XIAO ESP32-C3', cloud:{on:true, ok:true, ago:Math.round((t / 1000) % 60)}, time:t});
    },
    history(h){
      const n = h * 3600 / step, from = Date.now() - h * 3600e3;
      return wait({step, end:Date.now(), thr:st.thr, m1:H.m1.slice(-n), m2:H.m2.slice(-n),
        temp:H.temp.slice(-n), hum:H.hum.slice(-n), lux:H.lux.slice(-n), events:H.events.filter(e => e.t >= from)});
    },
    water(s){ const t = Date.now(); s = Math.min(s, st.maxRun); st.pumpEnd = t + s * 1000; st.lastWater = t; H.events.push({t, s, manual:true}); return wait({ok:1}); },
    stop(){ st.pumpEnd = 0; return wait({ok:1}); },
    settings(o){ st.thr = +o.thr; st.auto = !!+o.auto; st.maxRun = +o.max; return wait({ok:1}); },
    calibrate(p){ st.soil.forEach(s => s.cal = true); return wait({ok:1, done:[1,2]}); },
  };
})();

/* Demo ThingSpeak feed (preview of the online view: add ?online to the address) */
function demoTs(url){
  const h = demo.history(24);
  return h.then(H => {
    const n = H.m1.length, t0 = H.end - (n - 1) * H.step * 1000;
    const flags = 1 | 2 | 4 | 32 | 128 | 256 | (H.thr << 9);      // light sensor missing
    let feeds = H.m1.map((_, i) => ({created_at: new Date(t0 + i * H.step * 1000).toISOString(),
      field1: H.m1[i], field2: H.m2[i], field3: H.temp[i], field4: H.hum[i], field5: H.lux[i] ?? '', field6: 0, field7: 0, field8: flags}));
    H.events.forEach(e => { const i = Math.round((e.t - t0) / (H.step * 1000)); if (feeds[i]) feeds[i][e.manual ? 'field6' : 'field7'] = e.s; });
    if (url.includes('results=1&') || url.endsWith('results=1')) feeds = feeds.slice(-1);
    return {channel: {name: 'Plant monitor'}, feeds};
  });
}

/* ===== Start ===== */
if (!DEMO) $('demoNote').remove();
else if (ONLINE) $('demoNote').textContent = 'Preview of the online view with simulated data';
poll(); loadHistory();
setInterval(poll, POLL_MS);
setInterval(health, 1000);
setInterval(loadHistory, 5 * 60 * 1000);
</script>
</body>
</html>
)rawliteral";
