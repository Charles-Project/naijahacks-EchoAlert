<template>
  <b-form class="bg-form mt-6">
    <b-form-group label="Home address:" label-for="input-name" label-sr-only>
      <b-form-input id="input-name" v-model="name" type="text" required placeholder="Full Name"></b-form-input>
    </b-form-group>

    <b-form-group label="Home address:" label-for="input-phone" label-sr-only>
      <b-form-input id="input-phone" v-model="phone" type="phone" required placeholder="Phone Number"></b-form-input>
    </b-form-group>

    <b-form-group label="Home address:" label-for="input-email" label-sr-only>
      <b-form-input id="input-email" v-model="email" type="email" required placeholder="Email"></b-form-input>
    </b-form-group>

    <b-form-group id="input-group-1s" label="Home address:" label-for="input-address" label-sr-only>
      <b-form-input id="input-address" v-model="address" type="text" required placeholder="Address"></b-form-input>
    </b-form-group>

    <b-form-group id="input-group-2s" label="Your Password:" label-for="input-password" label-sr-only>
      <b-form-input
        type="password"
        id="input-password"
        v-model="password"
        required
        placeholder="Password"
      ></b-form-input>
    </b-form-group>

    <b-form-group id="input-group-3s" label="Your Password again:" label-for="input-password-again" label-sr-only>
      <b-form-input
        type="password"
        id="input-password-again"
        v-model="passwordRepeat"
        required
        placeholder="Retype Password"
      ></b-form-input>
    </b-form-group>

    <b-form-group id="input-group-4">
      <b-form-checkbox-group id="checkboxes-4">
        <b-form-checkbox value="me">Remember Me!</b-form-checkbox>
      </b-form-checkbox-group>
    </b-form-group>

    <b-button class="text-uppercase" block type="submit" variant="primary">signup</b-button>
    <p class="text-center mt-2">
      Forgot your password?
      <b-link>Click to reset</b-link>
    </p>
  </b-form>
</template>

<script>
export default {
  data() {
    return {
      fname: "",
      lname: "",
      email: "",
      phone: "",
      password: "",
      passwordRepeat: "",
      address: ""
    };
  }
};
</script>

<style scoped></style>
