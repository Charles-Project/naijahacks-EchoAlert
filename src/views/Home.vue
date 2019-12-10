<template>
  <div>
    <b-jumbotron class="head d-flex align-items-center flex-column border-0 jumbotron-fluid">
      <!-- <div class="d-flex align-items-start flex-column bd-highlight mb-3" style="height: 200px;"> -->
      <div class="container text-center my-auto">
        <!-- <span class="text-white mt-10">SmartEcho</span> -->
        <!-- <img class="img-fluid px-4" src="../assets/logo-white@3x.png" alt="altText" /> -->

        <div class>
          <h2 class="text-white">
            One chance to live in a safe <br />
            and conducive enironment. <br />
            Do so now.
          </h2>
        </div>

        <b-button to="auth" class="mt-3 text-uppercase font-weight-bolder" size="lg" variant="primary" href="#"
          >Sign Up Now</b-button
        >
      </div>
    </b-jumbotron>

    <!-- features -->
    <div class="text-center mt-6 container">
      <div class="row">
        <div class="col-lg-4">
          <img class="mb-3" src="../assets/svg/chat.svg" alt="Generic placeholder image" height="60" />
          <h2 class="my-3">Alert</h2>
          <p>
            SmartEcho will alert
            <br />the user via email and SMS
          </p>
        </div>
        <!-- /.col-lg-4 -->
        <div class="col-lg-4">
          <img class="mb-3" src="../assets/svg/loupe.svg" alt="Generic placeholder image" height="60" />
          <h2 class="my-3">Detection</h2>
          <p>
            SmartEcho detects unwanted
            <br />strangers around your home
          </p>
        </div>
        <!-- /.col-lg-4 -->
        <div class="col-lg-4">
          <img class="mb-3" src="../assets/svg/video-camera.svg" alt="Generic placeholder image" height="60" />
          <h2 class="my-3">Record</h2>
          <p>
            SmartEcho silently records
            <br />after alarm trigger
          </p>
        </div>
        <!-- /.col-lg-4 -->
      </div>
      <div class="row">
        <div class="col-12 text-center py-5">
          <b-button tag="a" to="auth" size="lg" variant="warning" class="text-uppercase px-5 border-0"
            >it's exactly what i need</b-button
          >
        </div>
      </div>
    </div>

    <footer class="container py-3">
      <div class="row">
        <div class="col-12 text-center">
          <p>
            Built by
            <span class="text-dark font-weight-bolder">Electrox-Genius</span> 💻💻💻
          </p>
        </div>
      </div>
    </footer>
  </div>
</template>

<script>
// @ is an alias to /src

export default {
  name: "home"
};
</script>

<style lang="scss" scoped>
.head {
  height: 100vh;
  background: url("../assets/2650393.jpg") no-repeat;
  // background-size: cover;
  // background-position: top;
}

.features {
  margin-top: 300px;
}
</style>
