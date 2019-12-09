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
.btn {
  border-radius: none !important;
}
</style>
