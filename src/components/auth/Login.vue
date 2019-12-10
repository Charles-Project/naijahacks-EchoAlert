<template>
  <!-- login form -->
  <b-form class="bg-form mt-6">
    <b-form-group id="input-group-1" label="Email address:" label-for="input-1" label-sr-only>
      <b-form-input id="input-1" v-model="email" type="email" required placeholder="Username/Email"></b-form-input>
    </b-form-group>

    <b-form-group id="input-group-2" label="Your Name:" label-for="input-2" label-sr-only>
      <b-form-input type="password" id="input-2" v-model="password" required placeholder="Password"></b-form-input>
    </b-form-group>

    <b-form-group id="input-group-4">
      <b-form-checkbox-group id="checkboxes-4">
        <b-form-checkbox value="me">Remember Me!</b-form-checkbox>
      </b-form-checkbox-group>
    </b-form-group>

    <b-button class="text-uppercase" block type="submit" variant="primary">login</b-button>
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
      email: "",
      password: ""
      // checked: []
    };
  }
};
</script>

<style scoped></style>
