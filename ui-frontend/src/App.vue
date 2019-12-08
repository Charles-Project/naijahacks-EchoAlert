<template>
  <div id="app">
    <the-header></the-header>
    <router-view />
  </div>
</template>

<script>
import TheHeader from "./components/TheHeader";

export default {
  components: {
    TheHeader
  }
};
</script>

<style lang="scss">
#app {
  font-family: "Avenir", Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}
</style>
