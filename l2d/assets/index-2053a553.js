(function(){const t=document.createElement("link").relList;if(t&&t.supports&&t.supports("modulepreload"))return;for(const n of document.querySelectorAll('link[rel="modulepreload"]'))r(n);new MutationObserver(n=>{for(const i of n)if(i.type==="childList")for(const c of i.addedNodes)c.tagName==="LINK"&&c.rel==="modulepreload"&&r(c)}).observe(document,{childList:!0,subtree:!0});function o(n){const i={};return n.integrity&&(i.integrity=n.integrity),n.referrerPolicy&&(i.referrerPolicy=n.referrerPolicy),n.crossOrigin==="use-credentials"?i.credentials="include":n.crossOrigin==="anonymous"?i.credentials="omit":i.credentials="same-origin",i}function r(n){if(n.ep)return;n.ep=!0;const i=o(n);fetch(n.href,i)}})();const s={NONE:0,IDLE:1,NORMAL:2,FORCE:3};function d(e){e.buttonMode=!0,e.on("pointerdown",t=>{e.dragging=!0,e._pointerX=t.data.global.x-e.x,e._pointerY=t.data.global.y-e.y}),e.on("pointermove",t=>{e.dragging&&(e.position.x=t.data.global.x-e._pointerX,e.position.y=t.data.global.y-e._pointerY)}),e.on("pointerupoutside",()=>e.dragging=!1),e.on("pointerup",()=>e.dragging=!1)}(async()=>{const e="./model/Miss Bai.model3.json",t=await PIXI.live2d.Live2DModel.from(e),o=new PIXI.Application({view:document.getElementById("scene"),autoStart:!0,resizeTo:window}),r=o.screen.width>o.screen.height?PIXI.Sprite.from("bg_w.png"):PIXI.Sprite.from("bg_h.png");r.width=o.screen.width,r.height=o.screen.height,o.stage.addChild(r),o.stage.addChild(t),t.x=0,t.y=-100,t.scale.set(.5),d(t),document.getElementById("talk").addEventListener("click",()=>{t.motion("speak5",void 0,s.NORMAL)}),document.getElementById("close").addEventListener("click",()=>{t.motion("mouthClose",void 0,s.FORCE)}),document.getElementById("shake").addEventListener("click",()=>{t.motion("shake",void 0,s.NORMAL)}),document.getElementById("eye").addEventListener("click",async()=>{t.motion("eye",void 0,s.NORMAL)}),console.log(t.scale.set)})();
