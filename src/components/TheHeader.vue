<template>
  <div id="nav">
    <b-navbar
      fixed="top"
      toggleable="sm"
      type="light"
      variant="none"
      class="bg-white"
    >
      <div class="container">
        <b-navbar-brand to="/" class="d-flex">
          <img
            class="mx-auto"
            height="30"
            src="../assets/logo.png"
            alt="SmartEcho logo"
          />
        </b-navbar-brand>

        <b-navbar-toggle target="nav-collapse">
          <small>👇🏾 Menu</small>
        </b-navbar-toggle>

        <b-collapse id="nav-collapse" is-nav>
          <!-- Right aligned nav items -->

          <b-navbar-nav class="ml-auto">
            <b-nav-item class="px-3" href="#">Help</b-nav-item>
            <b-nav-item class="px-3" to="auth">👨🏾Login</b-nav-item>
            <b-nav-form class="px-3">
              <b-button
                to="auth"
                variant="primary"
                class="my-2 my-sm-0 text-uppercase px-3"
                type="submit"
                >Sign Up</b-button
              >
            </b-nav-form>
          </b-navbar-nav>
        </b-collapse>
      </div>
    </b-navbar>
  </div>
</template>

<script>
export default {
  name: "TheHeader"
};
</script>

<style scoped lang="scss"></style>
