import Vue from "vue";
import App from "./App.vue";
import router from "./router";
import store from "./store/store";

import BootstrapVue from "bootstrap-vue";

Vue.use(BootstrapVue);

import "./sass/app.scss";
Vue.config.productionTip = false;

new Vue({
  router,
  store,
  render: h => h(App)
}).$mount("#app");
