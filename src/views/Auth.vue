<template>
  <div class="auth container pt-8">
    <div class="row">
      <div class="div col-10 offset-1 col-lg-6 offset-lg-3">
        <h2
          class="text-center text-primary"
        >{{ show ? "Log in" : "Sign up" }} to your SmartEcho account</h2>
        <transition name="slide-fade" mode="out-in">
          <login v-if="show"></login>
          <signup v-if-else="!show"></signup>
        </transition>

        <p class="text-center my-5">
          <b-button @click="show = !show" class="text-decoration-none" variant="link">
            {{
            show ? "Don't have account? Log in" : "Already have an account? Sign up"
            }}
          </b-button>
        </p>
      </div>
    </div>
  </div>
</template>

<script>
const Login = () => import("@/components/auth/Login");
const Signup = () => import("@/components/auth/Signup");
// import Login from "@/components/auth/Login";
// import Signup from "@/components/auth/Signup";
export default {
  data() {
    return {
      show: true
    };
  },
  components: {
    Login,
    Signup
  }
};
</script>

<style lang="scss" scoped>
/* Enter and leave animations can use different */
/* durations and timing functions.              */
.slide-fade-enter-active {
  transition: all 0.3s ease;
}
.slide-fade-leave-active {
  transition: all 0.8s cubic-bezier(1, 0.5, 0.8, 1);
}
.slide-fade-enter, .slide-fade-leave-to
/* .slide-fade-leave-active below version 2.1.8 */ {
  transform: translateX(10px);
  opacity: 0;
}
</style>
